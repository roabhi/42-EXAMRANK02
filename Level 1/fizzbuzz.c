/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:39:00 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/06 21:24:00 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int c)
{
	/*
	Use base10 "0123456789" to write the char passed in the function 

	so for 40 
	40 is greater than 9
	so sent it back to ft_putnbr(40/10) (4)  
	4 is NOT greater than 9 so write the following
	4%10 = 4

	the next digit from 40 is 0
	0 is not greater than 9 so write the following
	0 % 10 = 0
	*/	
	if (c > 9)
		ft_putnbr(c / 10);
	write(1, &"0123456789"[c % 10], 1); 
}

int	main(void)
{
	/*
	We use module (%) to get the remaining of a division
	int / 5 || int / 3 || or both
	if the remaining is 0 then it is a multiple
	of those same numbers. 
	Then print accordingly	
	*/
	
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
