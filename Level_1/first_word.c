/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:12:05 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/25 20:26:45 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // include write

/**
 * @brief 
 * 
 * This exercice asks to display the first word from a string
 * 
 * In order to do that we need to get rid of any previous spaces
 * and tabs (32 and 9 in ASCII code) to start from a point where 
 * there is printable chars
 * 
 * From that point we keep goinf until we found the next space or tab 
 * keeping in mind we still need to have any chars to go through 
 * since we may reach the end of the file
 * 
 * @param i num of params
 * @param params *char
 * @return int standard return for main
 */

int	main(int i, char **params)
{
	int	c;

	c = 0;
	if (i == 2)
	{
		while (params[1][c] == 32 || params[1][c] == 9)
			c++;
		while (params[1][c] != 32 && params[1][c] != 9 && params[1][c])
		{
			write(1, &params[1][c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
}
