/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:39:50 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/27 21:11:32 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // include write
#include <stdio.h> // include printf

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
			{
				j = j + 1;
			}
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
