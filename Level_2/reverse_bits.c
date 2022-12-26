/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:44:50 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/26 20:51:23 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // include write
#include <stdio.h> // include printf

// void	print_bits(unsigned char octet)
// {
// 	int				c;
// 	unsigned char	bit;

// 	c = 8;
// 	while (c >= 0)
// 	{
// 		bit = (octet >> c & 1) + '0';
// 		write(1, &bit, 1);
// 		c--;
// 	}
// }

/**
 * @brief 
 * 
 * Here in order to reverse the bits for a char
 * we need a var to keep adding the remainder (if any) of
 * dividing our octet by 2 times 2 (that would equals to res << 1)
 * then diving our itinial char value by 2 
 * 
 * @param octet 
 * @return unsigned char 
 */

unsigned char	reverse_bits(unsigned char octet)
{
	int c;
	unsigned char res;

	c = 8;
	res = 0;
	while (c >= 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		c--;
	}
	return (res);
}

// int	main(void)
// {
// 	static int	num = 2;
// 	static unsigned char	res = 0;	

// 	write(1,"\nEl bit normal es ", 19);
// 	print_bits(num);
// 	write(1,"\nEl bit al reves es ", 20);
// 	res = reverse_bits(num);
// 	print_bits(res);
// 	return (0);
// }
