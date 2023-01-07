/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:37:28 by rabril-h          #+#    #+#             */
/*   Updated: 2023/01/07 20:06:15 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // include printf AND NULL

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

// #include "list.h" //This needs to be included in exercice but we do not create it or deliver with exercice

int ascending(int a, int b)
{
	return (a <= b);
} // This is the function that will be used by machine as well. We do not include it in exercice either

void    print_list(t_list *lista)
{
    int c;
    
    c = 0;
    while (lista && lista->next)
    {
        printf("El elemento %i de la lista tiene un valor de %i\n", c, lista->data);
        lista = lista->next;   
        c++;     
    }
    printf("El elemento %i de la lista tiene un valor de %i\n\n", c, lista->data);
}

/**
 * @brief 
 * 
 * In this exercice the key is to redefine each time the first element of the list we are using in order to 
 * make as many loops as necessary every time we do a swap int in the list itself
 * In a "normal" scenario like with arrays would have to go from the first element up to the last
 * each time we do an operation.
 * 
 * That operation is made using a temp variable of type t_list tmp which has a reference to the first element
 * of that list as we first enter sort_list function. 
 * 
 * We only switch values but not the actual order of the list so
 * by saying that lst after a swap is again the reference passed to the function the first time we call sort_list we
 * are actually starting from the first element and again comparing values from that
 * first position in order to know if all items are correctly arranged this time around
 * 
 * The swap between the data is made also using a temp var in this case for the type of data t_list is using
 * 
 * Finally we again set the first element of the list as it was passed initially before sending back the ordered list under the original 
 * variable name (lst)
 * 
 * @param lst t_list
 * @param cmp function
 * @return t_list* 
 */

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int	swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if ( ( !(*cmp)(lst->data, lst->next->data) ) )
		{
            swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}

int main(void)
{
    t_list *lista;
    t_list lista1;
    t_list lista2;
    t_list lista3;
    t_list lista4;

    lista = &lista1;
    lista1.next = &lista2;
    lista2.next = &lista3;
    lista3.next = &lista4;
    lista4.next = NULL;

    lista1.data = 55;
    lista2.data = 3;
    lista3.data = 123;
    lista4.data = 0;
   
    print_list(lista);

    sort_list(lista, ascending);

    print_list(lista);
    
    return (0);
}
