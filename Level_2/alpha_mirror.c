/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:16:27 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/11 19:17:40 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
Similar to rotone from Level_1
Here we take the last ASCII value from either
upper or lowercase set of chars 'Z' or 'z' as reference. 
Then we substract the current char beign passed as arg
Then we add the value of either 'A' or 'a'
which are the first ASCII values from upper or lowercase char sets

So for 's' -> 115 we want to ouput 'h' -> 102
because there are the same chars form z to s 
than from a to h which are 8 positions

That would be lowercase so use 122 which is 'z' value
122 - 115 + 97 =  104

Same for uppercase but with different values for reference to 'Z'

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
				params[1][c] = (90 - params[1][c]) + 65;
			else if (params[1][c] >= 'a' && params[1][c] <= 'z')
				params[1][c] = (122 - params[1][c]) + 97;
			write(1, &params[1][c], 1);
			c++;
		}
	}
	write(1,"\n",1);
	return (0);
}
