/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:24:07 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/23 21:12:25 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h> // include strspn
// #include <stdio.h> // include printf

/**
 * @brief 
 * 
 * In orther to achieve the desired result we need to make use of
 * a helper function with a loop that can be broken at the same moment
 * we are not able to find the match we are looking for anymore from the main
 * function.
 * 
 * Here we will loop for a mismatch in the accept string 
 * up until the point it finds it or it wil return 0 if it reaches end of string
 * the default return value is a confirmation the match has been found which 
 * is what we capture in counter form the main function 
 * 
 * @param s 
 * @param c 
 * @return char* 
 */

int	ft_chrnstr(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief 
 * 
 * In this exercice my main problem was to wrap my head around what
 * actually native strpsn does. In contrast with the more easy strcspn
 * which negate matches between strings, here we want to actually know 
 * how many characters in *s are present in *accept so the scenario is likely 
 * going to be that s is shorter than accept and we are looking for an exact math in accept
 * for whatever we are passing as s.
 * 
 * For example
 * 
 * static char s[] = "this is the string";
 * static char accept[] = "is";
 * 
 * will return 0 because "this is the string as a whole"
 * is not founf in "is"
 * 
 * On the other hand
 * 
 * static char s[] = "is";
 * static char accept[] = "This is the string";
 * 
 * will return 2 because "is" is actually contained exactly
 * in "this is the string" with a lenght of 2 * 
 * 
 * 
 * @param *s
 * @param *accept
 * @return size_t 
 */

size_t	ft_strspn(const char *s, const char *accept)
{
	int		c;
	int		j;
	size_t	count;

	c = 0;
	j = 0;
	count = 0;
	while (s[c])
	{
		if (ft_chrnstr(accept, s[c]))
			count++;
		else
			break ;
		c++;
	}
	return (count);
}

// int main(void)
// {
// 	static char s[] = "geeks for";
// 	static char accept[] = "abc";

// 	// ft_strspn(s, accept);

// 	printf("\nEl resultado de strspn nativo con %s y %s es %lu\n", s, accept, strspn(s, accept));
// 	printf("el resultado de mi ft_strspn con %s y %s es %lu", s, accept, ft_strspn(s, accept));	
// 	return (0);
// }
