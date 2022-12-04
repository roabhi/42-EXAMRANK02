/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:39:00 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/04 21:05:05 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int c)
{
	if (c > 9)
		ft_putnbr(c / 10);
	write(1, &"0123456789"[c % 10], 1);
}

int	main(void)
{
	int	c;

	c = 1;
	while (c <= 100)
	{
		if (c % 5 == 0 && c % 3 == 0)
			write(1, "fizzbuzz", 8);
		else if (c % 3 == 0)
			write(1, "fizz", 4);
		else if (c % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(c);
		write(1, "\n", 5);
		c++;
	}
	return (0);
}
