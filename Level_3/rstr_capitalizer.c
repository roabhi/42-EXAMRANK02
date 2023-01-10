/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:06:06 by rabril-h          #+#    #+#             */
/*   Updated: 2023/01/10 17:18:19 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_lower_case(char ch)
{
	if (ch >= 'a' && ch <= 'z' )
		return (1);
	return (0);
}

int	is_upper_case(char ch)
{
	if (ch >= 'A' && ch <= 'Z' )
		return (1);
	return (0);
}

/**
 * @brief 
 * 
 * The function itself goes all the way until the end of the string
 * and checks if we are parsing anything other than a space or tab
 * 
 * If so, we check if the following char is a space, tab OR the end of the string
 * If so, we check if the char is a lower case char
 * If so, we change it
 * 
 * If we are not parsing the last letter from a word check if it is in uppercase
 * If so, we switch that char to lowercase
 * 
 * @param str char *
 */

void	rstr_capitalizer(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] != ' ' && str[c] != '\t')
		{
			if (str[c + 1] == ' ' || str[c + 1] == '\t' || !str[c + 1])
			{
				if (is_lower_case(str[c]))
					str[c] = str[c] - 32;
			}
			else if (is_upper_case(str[c]))
				str[c] = str[c] + 32;
		}
		write(1, &str[c], 1);
		c++;
	}
}

/**
 * @brief 
 * 
 * In this exercice as with the regular str_capitalizer we take as many string as passed as params
 * and for each one we perform the same operations
 * 
 * For rstr_capitalizar the goal is to capitalize the final letter for each word in the string at hand
 * and the rest have to be in lowercase
 * 
 * It is important that we skip the first param (which is the name of the compiled file) otherwise the 
 * assigment will fail because we are asked to only treat the string passed as arguments
 * 
 * @param i int number of params
 * @param params char...
 * @return int standard return
 */


int	main(int i, char **params)
{
	int	p;
	
	p = 0;
	if (i > 1)
	{
		p++;
		while (params[p])
		{
			rstr_capitalizer(params[p]);
			write(1, "\n", 1);
			p++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
