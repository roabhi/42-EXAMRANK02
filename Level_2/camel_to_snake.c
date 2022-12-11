/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:08:21 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/11 19:20:26 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
Similar to ulstr from Level_1
Here we only take into account uppercase chars
Once we find one we ouput '_' right away
Then we convert the uppercase to lowercase
which is always to be located 32 position after
the ASCII value of the current char
*/

int	main(int i, char **params)
{
	int	c;

	c = 0;
	if (i == 2)
	{
		while (params[1][c])
		{
			if (params[1][c] >= 'A' && params[1][c] <= 'Z')
			{
				write(1, "_", 1);
				params[1][c] = params[1][c] + 32;
			}
			write(1, &params[1][c], 1);
			c++;

		}
	}
	return (0);
}
