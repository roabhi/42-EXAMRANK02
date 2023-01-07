/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:44:21 by rabril-h          #+#    #+#             */
/*   Updated: 2023/01/07 18:18:22 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief 
 * 
 * Similar to expand_str this exercice makes use of a flag variable
 * in order to determine if we reached a point in the passed argument where certain 
 * conditions are met. In this case
 * 
 * 1) We are not reached the end of the string
 * 2) There is another char passed this point (kind of reiterating the previous)
 * 3) The current char is a space and the next one is not 
 * 
 * If these conditions are met, do not print anything, add a flag at this point 
 * parsing the string passed as argument
 * 
 * After that check it the current char meet the following criteria
 * 1) we are no reached the end of the string
 * 2) we are not parsing a space
 * 
 * If this conditions are meet check
 * 1) if we have a previous flag, if so, print a space
 * 2) set flag to 0 since we are going to print a char
 * 3) print the char
 * 
 * repeat
 * 
 * Basically if we take the following string 
 * 
 *  this        time it      will     be    more complex  .
 * 
 * The first chars are just ignored by the first lines at 
 * 
 * while (params[1][c] == ' ' || params[1][c] == '\t')
 * 	c++
 * 
 * This will leve the string as
 * this        time it      will     be    more complex  .
 * 
 * Then we enter the main loop
 * t is printed because we are not reached the end of the string and char is no space
 * h is printed because we are not reached the end of the string and char is no space
 * i is printed because we are not reached the end of the string and char is no space
 * s is printed because we are not reached the end of the string and char is no space
 * 
 * We are here
 * 
 *         time it      will     be    more complex  .
 * 
 * The next DOES NOT space qualifies as a flag because next char is still a space. 
 * In the else char also does not qualifies as printabble since it is space therefore nothibg is done and we increment c by one
 * 
 * The next DOES NOT space qualifies as a flag because next char is still a space. 
 * In the else char also does not qualifies as printabble since it is space therefore nothibg is done and we increment c by one
 * 
 * ....
 * 
 * we reached the space before [t]ime
 * 
 * This space DOES qualify as flag since next char is not a space but a t. Passed this point we increment c by one 
 * 
 * we reached [t]ime
 * 
 * This DOES not qualify as flag because is not a space. We go to else and since it is not a space 
 * we print the asked space since flag is 1. No matter what flag is set to 0 since we are printing a char
 * we print the char
 * 
 * And so on...
 * 
 * 
 * 
 * @param i num of args 0 index based
 * @param params params passed
 * @return int 
 */

int	main(int i, char **params)
{
	int	c;
	int	flag;

	if (i == 2)
	{
		c = 0;
		flag = 0;
		while (params[1][c] == ' ' || params[1][c] == '\t')
			c++;
		while (params[1][c])
		{
			if (params[1][c] && params[1][c + 1] && params[1][c]
				== ' ' && params[1][c + 1] != 32)
				flag = 1;
			else if (params[1][c] && params[1][c] != ' ')
			{
				if (flag == 1)
					write(1, " ", 1);
				flag = 0;
				write(1, &params[1][c], 1);
			}					
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
