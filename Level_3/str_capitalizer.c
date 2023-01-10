/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:05:15 by rabril-h          #+#    #+#             */
/*   Updated: 2023/01/10 17:24:26 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //include write

int	is_minus(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_mayus(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_separator(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

/**
 * @brief 
 * 
 * The function itself goes all the way until the end of the string
 * and checks if we are parsing anything other than a space or tab
 * 
 * Here we have a special case for the first word in case we are passing 
 * something like "a word is..."
 * 
 * For the rest
 * 
 * we check if the char at hand is NOT a space or tab AND if the previous char was a space or tab
 * If so, we check if the char is in lowercase and we change it to upper if needed.
 * 
 * Otherwise (if we are not at the beginning of a word)
 * we check if the char is uppercase, and if so we change it to lower.
 * 
 * 
 * @param str char *
 */

void	str_capitalizer(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		//if(!is_separaor(str[c]) && (is_separator(str[c + 1] || str[c + 1 == '\0'])
		if (c == 0 && !is_separator(str[c]))
		{
			//inicio de palara
			if(is_minus(str[c]))
				str[c] = str[c] - 32;
		}
		else if(c > 0 && !is_separator(str[c]) && is_separator(str[c - 1]))
		{
			//inicio de palabra
			if(is_minus(str[c]))
				str[c] = str[c] - 32;
		}
		else
		{
			//No es un inicio de palabra
			if(is_mayus(str[c]))
				str[c] = str[c] + 32;
		}
		write(1, &str[c], 1);
		c++;
	}
}

/**
 * @brief 
 * 
 * In this exercice as with the regular rstr_capitalizer we take as many string as passed as params
 * and for each one we perform the same operations
 * 
 * For rstr_capitalizar the goal is to capitalize the first letter for each word in the string at hand
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
	int	c;

	c = 0;
	if (i < 2)
	{
		write(1, "\n", 1);
	}
	else
	{
		c++;
		while (params[c])
		{
			str_capitalizer(params[c]);
			write(1, "\n", 1);
			c++;
		}
	}
	return (0);
}
