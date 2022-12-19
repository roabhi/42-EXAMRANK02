/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:23:36 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/19 17:22:07 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/**
 * @brief
 *
 * In order to reverse a string in memory by changing the order
 * of their char positions we need a temporary variable where to store
 * one of the values while we do the swap
 *
 * The loop itself will actually just reach half of the lengh of the string
 * since as we go through each char we increase the count on one side
 * while decreasing the count on the other end (the one stating from last char)
 * as stated in the while (j < c)
 *
 * Before we start the substition loop we need to substract 1 to the lengh of the
 * string to avoid the null terminated char '\0'
 *
 * Then we take the very first char from the start, store it in a temp variable
 * assign the first char the value of last char, then we use temp to set the last char
 * that will become the previous first
 *
 * As mentioned as we increment the count from the begining and decrease the count from the end
 * we will reach half of the length of the string with all chars already swaped.
 *
 * Then we return the result which is the same string and not a copy or anything else
 *
 * @param str char *
 * @return char *
 */

char	*ft_strrev(char *str)
{
	int		c;
	int		j;
	char	temp;

	c = 0;
	j = 0;
	while (str[c])
		c++;
	c--;
	while (j < c)
	{
		temp = str[j];
		str[j] = str[c];
		str[c] = temp;
		c--;
		j++;
	}
	return (str);
}

// int	main(void)
// {
// 	// static char str[] = "abcdefghijklmnopqrstuvwxyz";
// 	// static char str2[] = "abcdefghijklmnopqrstuvwxyz";
// 	static char str3[] = "abcdefghijklmnopqrstuvwxyz";

// 	char *result;

// 	result = ft_strrev(str3);

// 	printf("El resultado es %s", result);

// 	// printf("%s reversed es %s", str, ft_strrev(str2));
// 	return (0);
// }
