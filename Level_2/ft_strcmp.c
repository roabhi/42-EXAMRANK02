/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:48:06 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/17 20:19:47 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

/**
 * @brief 
 * 
 * To get a copy of the strcmp from the system
 * (which tries to declare if two string are / are not the same) 
 * we need a loop that takes care of the criteria
 * we are looking (or not looking for in this case)
 * since what we are going to return
 * is a substraction of the difference in ASCII terms between the first meeting
 * occurrence while comparing the two string chart by chart 
 * or 0 if the strings are actually the same
 * 
 * So for example if 
 * s1 = "Hello"
 * s2 = "World"
 * 
 * The first occurence (difference) is going to be found 
 * at the very first letter since 'H' from "Hello" (s1)
 * is not equal to 'W' from "World" (s2)
 * 
 * That is going to return 72 - 87 = -15 
 * That is beacuse H equals 72 and W equals 87 in ASCII values
 * 
 * So, to make sure that as we go looping through each char 
 * from each string they meet the desired criteria (are the same)
 * we can make use of C low level capabilities in order 
 * to achieve the desired result (0 is they are the same, a number is the are not)
 * 
 * Hence our conditional requirement for the loop has to include
 * 
 * 1) We are not at the end of the s1 string
 * 2) we are not at the end of the s2 string
 * 3) s1[c] and s2[c] are the same
 * 
 * Go throgh each char expecting to find same values
 * if not, at the first dissagrement, return the difference
 * between the found values at the found position
 * 
 * @param s1 char
 * @param s2 char
 * @return int 
 */

int	ft_strcmp(char *s1, char *s2)
{
	int	c;

	c = 0;
	while (s1[c] && s2[c] && s1[c] == s2[c])
		c++;
	return ((int)(s1[c] - s2[c]));
}

// int	main(void)
// {
// 	static char s1[] = "Hello";
// 	static char s2[] = "Hello";

// 	printf("el resultado del string compare del sistema es %i ", strcmp(s1, s2));
// 	printf("el resultado de mi string compare es %i ", ft_strcmp(s1, s2));

// }
