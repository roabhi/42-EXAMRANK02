/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:59:53 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/25 20:32:52 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // include write

/**
 * @brief 
 * 
 * This exercice is similar to first_word
 * but here the challenge is to know where to start 
 * printing out chars since it has to be the last word
 * 
 * In order to to that we go first through the string looking for 
 * a match with these conditions for the char at hand
 * 
 * 1) char is a space
 * 2) the next char from this space is not the end of string 
 * 3) the next char from this found space is not another space or tab
 * 
 * if all criteria is found we set that point at the starting point for the last word
 * 
 * we keep going until there is no more string to go through so at this point whatever
 * match we found has to be the last word
 * 
 * From that point on we just make sure we keep printing as long as there anything to print out
 * and that those printed chars are not spaces or tabs again (32 and 9 in ASCII values)
 * 
 * If params are not equal to 2 that means we either trying to use more params that needed or there
 * are no params so just print "\n"
 * 
 * @param i number of params
 * @param params *char 
 * @return int standard return for main
 */

int	main(int i, char **params)
{
	int c;
	int start;
	
	if (i == 2)
	{
		c = 0;
		while (params[1][c])
		{
			if (params[1][c] == 32 && params[1][c + 1] && params[1][c + 1] != 32 && params[1][c + 1] != 9)
				start = c + 1;
			c++;
		}
		while (params[1][start] && params[1][start] != 32 && params[1][start] != 9)
		{
			write(1, &params[1][start], 1);
			start++;
		}
	}
	write(1,"\n", 1);
	return (0);
}
