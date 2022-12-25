/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:40:25 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/25 21:01:44 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // include printf

/**
 * @brief 
 * 
 * In this exercice we need to determine the greatest value
 * from a set of int inside an array knowing the length of
 * that given array
 * 
 * In order to do that we just need to reserve a var to
 * hold the current max value found as we go through the array
 * 
 * We initialice the greatest value with whatever value comes
 * at the first position in the array. Then we compare that to the 
 * next one and if greater we switch that new value to max. 
 * 
 * An so on.
 * 
 * We use c as a counter that will got up until the given length
 * of the array. 
 * 
 * @param tab array[] of ints
 * @param len lengh of array
 * @return int max value from the array
 */

int	max(int *tab, unsigned int len)
{
	unsigned int c;
	int max;
	
	c = 0;
	max = tab[0];
	while (c < len)
	{
		if (tab[c + 1] > max)
			max = tab[c + 1];
		c++;
	}
	return (max);
}

// int	main(void)
// {
// 	static int	array[] = {123,2,33,455,52};

// 	printf("El valor max del array es %i", max(array, 5));
	
// 	return (0);
// }
