/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:23:44 by rabril-h          #+#    #+#             */
/*   Updated: 2023/01/10 21:07:44 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief 
 * 
 * This exercice is pretty simple since in order to find if a 
 * string is "hidden" in another string the only thing we need to
 * do is to increment a counter for the first string each time we find
 * a match based on an iterartion from the second string (supposedly the larger one)
 * 
 * so each time we find a match we increment the counter for our target and if 
 * at the end at the other string (our reference) the target string ends with 
 * a null terminated char '\0' it means it is "hiden" in the reference in the same
 * order even when matches are separated by several positions.
 * 
 * @param i int
 * @param params char *
 * @return int standard return
 */

int	main(int i, char **params)
{
	int	c;
	int	x;

	if (i == 3)
	{
		c = 0;
		x = 0;
		while (params[2][c] && params[1][x])
		{
			if (params[2][c] == params[1][x])
				x++;
			c++;
		}
		if (params[1][x] == '\0')
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
