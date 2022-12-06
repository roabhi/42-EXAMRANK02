/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:28:34 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/06 21:09:22 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* ====================================
If we take 'a'/97 we expect 'n'/110 
so substract the defaulr value of 'a'/97 
to first value alphabet which is 'a'/97
then add 13 which is the value we want as rot_13
then use 26 as module (whole alphabet from 'a' to 'z' is 26 characters)
to get the remaining value which in the case for 'a' would be 13
then add again the first value of the alphabet which is 'a'/97

so for 'a' that would be 97 - (97 + 13) = 13 | 13 % 26 = 13 | 13 + 97 = 110 which is n

Same for uppercase but for their own ASCII values
 
so for 'R' that would be 82 - (65/A + 13) = 4 | 4 % 26 = 4 | 4 + 65 = 69 which will be E

======================================*/

int	main(int i, char **params)
{
	int	c;

	c = 0;
	if (i == 2)
	{
		while (params[1][c])
		{
			if (params[1][c] >= 'a' && params[1][c] <= 'z')
				params[1][c] = (params[1][c] - 'a' + 13) % 26 + 'a';
			else if (params[1][c] >= 'A' && params[1][c] <= 'Z')
				params[1][c] = (params[1][c] - 'A' + 13) % 26 + 'A';
			write(1, &params[1][c], 1);
			c++;
		}
	}
	write(1,"\n", 1);
	return (0);
}
