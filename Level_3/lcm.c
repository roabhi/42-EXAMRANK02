/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:28:59 by rabril-h          #+#    #+#             */
/*   Updated: 2023/01/02 21:36:21 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h> // include printf

/**
 * @brief 
 * 
 * In order to achieve the goal of the exercice
 * which is to find a common number between the two passed
 * params which is divisible by the two of them withut floats
 * we need to do
 * 
 * 1) get to know which is the bigger number between the two params
 * 2) set that number as strating point for the operation
 * 3) go forever until in increments of 1 until we reach
 * a point where a de division of that number by a and b is 0
 * 
 * so for example for 5 and 7
 * 
 * 1) 7 is bigger than five
 * 2) n = 7
 * 3) is there a float for 7 / 7 ? No. is there  float between 7 / 5? Yes
 * 3) is there a float for 8 / 7 ? Yes. is there a float between 8 / 5? Yes
 * 3) is there a float for 9 / 7 ? Yes. is there a float between 9 / 5? Yes
 * 3) .....
 * 3) is there a float for 35 / 7 ? No. is there a float between 35 / 5? No
 * 
 * @param a uint
 * @param b uint
 * @return unsigned int 
 */

unsigned int	lcm(unsigned int a, unsigned int b)
{
   unsigned int	n;
   
   if ((int)a <= 0 || (int)b <= 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		n++;
	}
}


int main(void)
{
	static int a = 5;
	static int b = 7;

	printf("El lcm de %i y %i es %i", a, b, lcm(a,b));
}
