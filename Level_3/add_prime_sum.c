/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:00:48 by rabril-h          #+#    #+#             */
/*   Updated: 2023/01/09 17:38:30 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	ft_simple_atoi(char *str)
{
	int	c;
	int	res;

	c = 0;
	res = 0;
	while (str[c])
	{
		if (str[c] == ' ' || str[c] == '\t')
			c++;
		if (str[c] == '+' || str[c] == '-')
		{
			if (str[c] == '-')
				return (0);
			c++;
		}
		while (str[c] >= '0' && str[c] <= '9')
		{
			res = (res * 10) + str[c] - '0';
			c++;
		}
	}
	return (res);
}

/**
 * @brief 
 * 
 * In order to know if a num is a prime
 * which is a number only divisible by itself and in our case by 1
 * since negatives are not taken into account we use the following 
 * formula
 * 
 * We start with a divider of 2 since 1 and 2 are prime nmbers and we increment that count until our number / 2 is less or equal to
 * 2 or a greater number as go up in our quest for a division with a module of 0 
 * that will imply that our current num is NOT a prime
 * 
 * If in any of the operations we find a division with a remainder of 0 we return 0 as numner is not a prime
 * otherwise we have a prime to add to our sum of prime numbers
 * 
 * so for 5 as params
 * at this point we have as first time in ft_is_prime(5)
 * 
 * div is 2 
 * div is less of equal 5 / 2 = 2 so 
 * is 5 / 2 ==0
 * no
 * increment div wich is 3
 * 
 * div is 3
 * div is equal or less than 5/2 = 2 no so
 * return 1, 5 is a prime number that will be added to sum
 * 
 * now we get 4 insiide ft_is_prime()
 * 
 * div is 2
 * div is less of equal 4 / 2 = 2 so 
 * is 4 / 2 ==0
 * yes
 * 
 * return 0, 4 is not a prime
 * 
 * now we get 3 insiide ft_is_prime()
 * 
 * div is 2
 * div is less or equal to 3/2 = 1?
 * 
 * no return 1, 3 is a prime
 * 
 * now we get 2 insiide ft_is_prime()
 * 
 * div is 2
 * div is less or equal to 2/2 = 1?
 * 
 * no return 1, 2 is a prime number
 * 
 * end, sum will be 5 + 3 + 2 = 10
 * 
 * @param num int
 * @return int true or false by 1 or 0
 */

int	ft_is_prime(int num)
{
	int	div;

	div = 2;
	while (div <= num / 2)
	{		
		if (num % div == 0)
			return (0);
		div++;
	}
	return (1);
}

/**
 * @brief 
 * 
 * In this exercice the most difficult part to get besides
 * the actual calculation to figure out if a number is a prime
 * is to create the support functions to turn strings to numbers
 * and the other way around, that is create a custom atoi and a custom 
 * putnbr
 * 
 * Once we get the passed number as string we convert that into 
 * a int. Only positive values are allowed so if the input is negative we
 * will asign num to 0 and we will never enter the following loop
 * Finally we wildisplay sum which is 0 using in etiher case a putnbr with base of 10
 * 
 * Otherwise we perfor the calculations in order to know if a num is a prime.
 * If so we add that to our final output sum
 * 
 * We need to know for each number under the number passed as param so we take one 
 * as delimiter since there are no prime numbers below 1
 * 
 * If we are passed 5 as params wi will pass to ft_is_primer() from 5 to 2
 * 
 * @param i 
 * @param params 
 * @return int 
 */

int	main(int i, char **params)
{
	int	c;
	int	num;
	int	sum;

	c = 0;
	num = 0;
	sum = 0;	
	if (i == 2)
	{
		num = ft_simple_atoi(params[1]);
		while (num > 1)
		{
			if (ft_is_prime(num))
				sum = sum + num;
			num--;
		}
		ft_putnbr(sum);
	}
	write(1, "\n", 1);
	return (0);
}
