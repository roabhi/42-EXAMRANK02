/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:39:50 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/27 21:26:04 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // include write

/**
 * @brief 
 * 
 * In orther to solve this apparently complicated problem
 * we actually take a very smart approach which consist on 
 * looping through s2 (since it is the string which is ruling the printing)
 * and for each time we found a mathinc char in s2 able to print s1 we increase
 * the index for the match we expect to find in s1 for the next one
 * 
 * By the end of s2 we are going to end up either with a null terminated string
 * for s1 (in case the print is possible) or with remaining chars still not found
 * in s2.
 * 
 * If the string is null termintated a.k.a we found all letters from s1 in s2
 * we print out s1 otherwise we return "\n"
 * 
 * @param i int
 * @param params char **
 * @return int standar main return
 */


int	main(int i, char **params)
{
	int	c;
	int	j;
	
	if (i == 3)
	{
		c = 0;
		while (params[2][c])
		{
			if (params[2][c] == params[1][j])
				j = j + 1;
			c++;
		}
		if (!params[1][j])
		{
			c = 0;
			while (params[1][c])
			{
				write(1, &params[1][c], 1);
				c++;
			}
		}		
	}
	write(1, "\n", 1);
	return (0);
}
