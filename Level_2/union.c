/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:28:13 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/27 20:34:10 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // include write

/**
 * @brief 
 * 
 * @param str 
 * @param ref 
 * @return int 
 */

int	char_is_present(char *str, char ref)
{
	int	c;

	c = 0;
	while (str[c])
	{
		if (str[c] == ref)
			return (1);
		c++;
	}
	return (0);
}

int	already_printed(char *str, char ref, int index)
{
	int	c;

	c = 0;
	while (c < index)
	{
		if (str[c] == ref)
			return (1);
		c++;
	}
	return (0);
}


/**
 * @brief 
 * 
 * This exercice is similar to inter but in this case we do not want to print 
 * just one time any existing matches between to string but to print just once
 * any characters appearing in etiher of the strings
 * 
 * so for example 
 * 
 * s1 = "whatever"
 * s2 = "fuckever"
 * 
 * the expected result is "whatevrfuck"
 * 
 * In order to do that we have a couple of helper functions
 * 
 * 1) already_printed will check if the char at hand is alredy present (thus printed)
 * previosuly in a string
 * 
 * 2) char_is_present will help us know if a particulat char is or ins't included in a string
 * 
 * So, start with the first string and figure out if the char at hand is been already printed 
 * or present before in the string prior to that point. if not we just print that.
 * 
 * The we go for the second string in which first we ask if the char is already present in s1
 * which we just printed out. If not, we have a candidate for printing. 
 * 
 * Then as a candidate we make sure that prior to that point we did not printed that same char already
 * for s2
 * 
 * @param i int
 * @param params ** char
 * @return int standard return
 */


int	main(int i, char **params)
{
	int	c;
	
	if (i == 3)
	{
		c = 0;
		while (params[1][c])
		{
			if (!already_printed(params[1], params[1][c], c))
			{
				write(1, &params[1][c], 1);
			}
			c++;
		}
		c = 0;
		while (params[2][c])
		{
			if (!char_is_present(params[1], params[2][c]))
			{
				if (!already_printed(params[2], params[2][c], c))
					write(1, &params[2][c], 1);
			}
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
