/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:59:25 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/27 20:08:23 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // import write

/**
 * @brief 
 * 
 * The goal of this exercice is to print a char (withut sign) 
 * which would be essentially a number into
 * its binary form. In order to to that we loop through each bite
 * which is 8 times as a char is made of 8 bits.
 * 
 * For the conversion we use a base of 128 since a binary represtantion
 * of a char is as follows for the number 2
 * 
 * 128	64	32	16	8	4	2	1
 * 0	0	0	0	0	0	1	0
 * 
 * void	print_bits(unsigned char octet)
 * {
 * 	int	c;
 *	int	base;
 *
 *	c = 8;
 *	base = 128;
 *	while (c > 0)
 *	{
 *		if (octet < base)
 *			write(1, "0", 1);			
 *		else
 *		{
 *			write(1, "1", 1);
 *			octet = octet - base;
 *		}
 *		base = base / 2;
 *		c--;
 *	}
 * }
 * 
 * 
 * @param octet unsigned char
 */

/**
 * @brief 
 * 
 * Shorter version using bit operators
 * 
 * here we equal the bit we are going to write to the value
 * of the position marked by the counter and we use the AND / &
 * operator to determine if the output will b 0 or 1. 
 * 
 * The only case it can be 1 is that the result from (octet >> c) 
 * is also one, otherwise it will be zero. Then we add '0' in order
 * to output the result in terminal
 * 
 * @param octet unsigned char
 */


void	print_bits(unsigned char octet)
{
	int				c;
	unsigned char	bit;

	c = 8;
	while (c >= 0)
	{
		bit = (octet >> c & 1) + '0';
		write(1, &bit, 1);
		c--;
	}
}

// int	main(void)
// {
// 	static int num = 2;

// 	write(1, "\nEl resultado de 2 en binario es ", 34);
// 	print_bits(num);
// 	write(1,"\n", 1);

// 	return (0);
// }
