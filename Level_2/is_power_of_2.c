/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:21:58 by rabril-h          #+#    #+#             */
/*   Updated: 2023/01/02 21:26:34 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // include printf

/**
 * @brief 
 * 
 * This is a simple exercicie to determine is a number is nor not 
 * power of 2
 * 
 * In order to do that we pass the number without sign and we
 * go from 1 until that number multiplying it * 2 each iteration
 * if we have a match at some point then number is power of two
 * 
 * @param n unsigned int
 * @return int boolean
 */


int is_power_of_2(unsigned int n)
{
    unsigned int number = 1;
	
	if ((int) n < 0)
		return (0);
	while(number <= n)
	{
		if (number == n)
		{
			return 1;
		}
		number = number * 2;
	}
	return 0;
}

int main(void)
{
    int num;

    num = 250;
    printf("\nel numero %i es potencia de 2? -> %i", num, is_power_of_2(num));
    return (0);
}
