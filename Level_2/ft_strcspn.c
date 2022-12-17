/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:22:07 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/17 21:13:08 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

/**
 * @brief 
 * 
 * This exercice is similar to strcmp but this time we
 * do not look for the first difference between chars 
 * between two string but we want to find (as strcspn does)
 * first time an occurrence happens in a string compared
 * to a set of chars passed as another string. 
 * 
 * The return number (size_t) will get how many chars in the original 
 * string DOES NOT match the string passed as reference
 * 
 * So for example
 * 
 * s1 = "This is the source string"
 * s2 = "axle"
 * 
 * We need to go each char in s1 trying find either "a", "x", "l" or "e"
 * If we do, then we will return how many chars from the original string 
 * DID NOT match any of the s2 chars so far.
 * 
 * This time the first ocurrence is a "e" from "This is th(e)" since
 * e is included un "axle" at the last position
 * 
 * So we will return c as the times we went through the previos chars without
 * finding a match, in this case 10 since e from s1 is located at position 11
 * and we are using 0 based indexes
 * 
 * If s1 does not have any chars includes in s2 we just return the length of s1
 * 
 * @param s char
 * @param reject char
 * @return size_t 
 */

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	c;
	int	r;

	c = 0;
	while (s[c])
	{
		r = 0;
		while (reject[r])
		{
			if (reject[r] == s[c])
				return (c);
			r++;
		}
		c++;
	}
	return (c);
}

// int	main(void)
// {
// 	static char s1[] = "This is the source string";
// 	static char s2[] = "zl";

// 	printf("\nthe ouput from system strcspn is %lu\n", strcspn(s1, s2));
// 	printf("the ouput from my strcspn is %lu", ft_strcspn(s1, s2));
// 	return (0);
// }
