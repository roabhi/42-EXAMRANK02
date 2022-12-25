/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 21:14:19 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/25 19:21:04 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h> // include printf
#include <unistd.h> //include write

/**
 * @brief 
 * 
 * This helper function takes 3 params
 * 
 * *str is the string passed as first argument as params in main function
 * ref is the char we are looking for a repetition early on in *str
 * index is the position from *str were are checking and the limit 
 * we will use to see if the char is already been printed or not
 * 
 * 
 * if we find a match we return 1 / yes if not 0 / not
 * 
 * @param str *char
 * @param ref char
 * @param index int
 * @return int boolean
 */


int	ft_already_printed(char *str, char ref, int index)
{
	int x;

	x = 0;
	while (x < index)
	{
		if (str[x] == ref)
			return (1);
		x++;
	}
	return (0);
}

/**
 * @brief 
 * 
 * This exercice consist of iterating for each of the
 * characters of first string each one of the chars of
 * the second one and see if there is a match
 * 
 * if there is one we need to check if the char is already present eariler in the 
 * string / already printed
 * 
 * If NOT we are safe to print
 * that char since the exercicie wants us to avoid doubles
 * 
 * after we found the answer we were lookig for (chars is repeat earier or not)
 * we exit the loop for that particular char
 * 
 * @param i int number of params
 * @param params params
 * @return int standard return 
 */

int	main(int i, char **params)
{
	int	c;
	int	j;
	
	c = 0;
	if (i == 3)
	{
		while (params[1][c])
		{
			j = 0;
			while (params[2][j])
			{
				if (params[1][c] == params[2][j])
				{
				   if (!ft_already_printed(params[1], params[1][c], c))
				   {
						write(1, &params[1][c], 1);
						break ;
				   }
				}
				j++;
			}
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
