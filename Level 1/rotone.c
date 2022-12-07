/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:13:06 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/07 19:20:15 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* ====================================
We only need to take into account if we
looking at the 'z' or 'Z' char in order
to take the 'a' or 'A' letter
otherwise it works the same [currentchar] + 1
==================================== */

int	main(int i, char **params)
{
	int	c;
	
	c = 0;
	if (i == 2)
	{
		while (params[1][c])
		{
			if (params[1][c] == 'z' || params[1][c] == 'Z')
				params[1][c] = params[1][c] - 25;
			else if ((params[1][c] >= 'a' && params[1][c] <= 'x')
				|| (params[1][c] >= 'A' && params[1][c] <= 'X'))
				params[1][c] = params[1][c] + 1;
			write(1, &params[1][c], 1);
			c++;
		}
	}
	write(1,"\n", 1);
	return (0);
}
