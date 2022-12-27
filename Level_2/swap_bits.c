/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:20:58 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/27 18:27:23 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * 
 * In this exercicie we make use of the bite wise operators
 * to swap the first 4 bits with the other 4 bits from 
 * an unsigned char
 * 
 * The OR operator is used to output 1 whenever at least
 * one of the bits is 1 so that wat we make originals are respected
 * as the swap takes place
 * 
 * @param octet 
 * @return unsigned char 
 */

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
