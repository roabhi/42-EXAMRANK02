/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:12:05 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/04 20:33:34 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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