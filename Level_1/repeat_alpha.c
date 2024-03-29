/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:51:43 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/07 19:31:07 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
in order to repeat the char x times
we always substract the distance from this letter 
in its own range - 1 to get where the current char is

so for exmaple for 'r' we would substract its value 
which is 114 - 96 which is the position of 'a' in 
ASCII table - 1. 'a' value is 97. we get 18 
which is the position of r in the alphabet

Same for uppercase but initial value / 'A' is not
97 but 65 so use 64 which is 65 - 1

*/

int	ft_strlen(char *str)
{
	int	c;
	
	c = 0;
	while (str[c])
		c++;
	return (c);
}

int	main(int i, char **params)
{
	static int	c = 0;
	int			j;

	if (i == 2 && ft_strlen(params[1]) > 0)
	{
		while (params[1][c])
		{
			j = 0;
			if (params[1][c] >= 'a' && params[1][c] <= 'z')
			{				
				while (j < (params[1][c] - 96))
				{
					write(1, &params[1][c], 1);
					j++;
				}
			}
			else if (params[1][c] >= 'A' && params[1][c] <= 'Z')
			{
				while (j < (params[1][c] - 64))
				{
					write(1, &params[1][c], 1);
					j++;
				}
			}
			else
				write(1, &params[1][c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
