/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:58:45 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/06 19:45:05 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	
	c = ft_strlen(params[1]) - 1;
	if (i == 2)
	{
		while (c >= 0)
		{
			write(1, &params[1][c], 1);
			c--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
