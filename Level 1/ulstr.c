/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:11:12 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/07 19:24:14 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* ====================================
The reverse case is allways located 32
positions after or before the char
value depending on the case so
+32 or -32 will always reflect changes
on the same letter / char
==================================== */

int	main(int i, char **params)
{
	int	c;
	
	c = 0;
	if (i == 2)
	{
		while (params[1][c])
		{
			if (params[1][c] >= 'a' && params[1][c] <= 'z')
				params[1][c] = params[1][c] - 32;
			else if (params[1][c] >= 'A' && params[1][c] <= 'Z')
				params[1][c] = params[1][c] + 32;
			write(1, &params[1][c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
