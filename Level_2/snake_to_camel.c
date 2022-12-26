/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:33:17 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/26 20:51:18 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief 
 * 
 * This is similar to camel_to_snake but in this case
 * we are looking for a "_" or 95 in ASCII code
 * Once we found it we just increment the count by one so we
 * do not print it and then switch whatever letter is there to
 * its uppercase value by substracting 32 which is the value
 * of separation between the same letters with different cases from lower
 * to upper in this case
 * 
 * @param i 
 * @param params 
 * @return int 
 */

int	main(int i, char **params)
{
	int	c;
	
	if (i == 2)
	{
		c = 0;
		while (params[1][c])
		{
			if (params[1][c] == 95)
			{
				c++;
				params[1][c] = params[1][c] - 32;				
			}
			write(1, &params[1][c], 1);
			c++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
