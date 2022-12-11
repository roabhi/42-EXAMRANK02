/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:26:41 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/07 19:21:22 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/* ====================================
We ony accept single letters as 2 and 3 param 
so no "xx" just "x" as char to search and char to replace
use length of those params to control errors 
as well as if needed params are not satisfied
loop for char and replace to substitute 
then print substition
if not match is found original string will be still printed
as subject demands
==================================== */

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
	int	c;

	c = 0;
	if (i == 4 && ft_strlen(params[2]) == 1 && ft_strlen(params[3]) == 1)
	{
		while (params[1][c])
		{
			if (params[1][c] == params[2][0])
				params[1][c] = params[3][0];
			write(1, &params[1][c], 1);
			c++;
		}
	}
	write(1,"\n",1);
	return (0);
}
