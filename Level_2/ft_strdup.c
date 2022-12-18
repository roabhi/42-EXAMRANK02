/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:39:07 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/18 16:07:26 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <libc.h> // import strdup
// #include <stdio.h> // import printf
#include <stdlib.h> // import malloc

/**
 * @brief 
 * 
 * First malloc allocation in EXAM.
 * 
 * Here we need to get a copy (in memory) from the string
 * passed argument to ft_strdup so it can be used outside
 * the function later on via pointer
 * 
 * In order to do that we need to "memory allocate" / malloc
 * enough space too hold the string. 
 * 
 * We use char as unit messaure * the length of the orignal
 * string passed as argument + 1 so we can close the string 
 * with null termination \0
 * 
 * If we do not have success in the memory allocation just
 * return NULL and stop the process.
 * 
 * Otherwise make an exact copy from each char position from
 * the original string.
 * 
 * Finally, close the string with \0 and make sure we return 
 * a pointer reference using (char *)
 * 
 * Note: we reuse / reset c as counter for both operations
 * first to find the length of src to allocate space, then as
 * counter for the copy itself
 * 
 * @param src *char
 * @return char* 
 */

char	*ft_strdup(char *src)
{
	int		c;
	char	*copy;
	
	c = 0;
	while (src[c])
		c++;
	copy = malloc(sizeof (char) * c + 1);
	if (!copy)
		return (NULL);
	c = 0;
	while (src[c])
	{
		copy[c] = src[c];
		c++;
	}
	copy[c] = '\0';
	return ((char *)copy);
}

// int	main(void)
// {
// 	static char str[] = "This is a string";

// 	printf("\nLa copia de -> %s <- usando strdup nativo es = %s\n", str, strdup(str));
// 	printf("La copia de -> %s <- usando ft_strdup es = %s", str, ft_strdup(str));	
// 	return (0);
// }
