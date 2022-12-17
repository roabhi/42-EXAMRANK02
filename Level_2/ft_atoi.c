/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:51:27 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/17 19:47:23 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h> // include printf
// #include <libc.h> // include atoi

/**
 * 
 * 
 * To implement a copy of the system atoi we need
 * 
 * 1) To first get rid of the initial spaces and tabulations like chars
 * prior yo find a sign or a number while increasing the char 
 * count as we go through the passed *str
 * 
 * 2) Then we check if there is a sign and if negative we take change sign
 * for the final output we will return and we increment c as we
 * want to look for the first char inside the '0' and '9' or 48 and 57 ASCII values
 * 
 * 3) Now for the conversion and as we keep finding chars
 * between '0' and '9' we do as follows for each char we handle we do:
 * 
 * char * 10 (to place the char into its right decimal position)
 * then we add (the current char being treated) - 0 
 * which will convert it to num by substracting the char minus null
 * 
 * So for 4525 we do:
 * 4 -> res = (current res which is 0 * 10) + 4 - 0 = 0 + 4 = 4
 * 5 -> res = (current res which is 4 * 10) + 5 - 0 = 40 + 5 = 45
 * 2 -> res = (current res which is 45 * 10) + 2 - 0 = 450 + 2 = 452
 * 5 -> res = (current res which is 452 * 10) + 5 - 0 = 4520 + 5 = 4525 
 * 
 * Any letters, signs or other characters found after the first number
 * are not taken into account so 4561--++xx456 will have to output just 4651
 * 
 * then if the input would have been -4525 we multiply 
 * res (which would be 4525) * -1 = -4525
 * 
 * 
 * */

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;
	int	c;

	res = 0;
	c = 0;
	sign = 1;
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			sign = -1;
		c++;
	}
	while (str[c] >= 48 && str[c] <= 57)
	{
		res = (res * 10) + str[c] - '0';
		c++;
	}
	return (sign * res);
}

// int	main(int i, char **params)
// {
// 	if (i == 2)
// 	{
// 		printf("\nEl resultado del atoi nativo con el string %s es %d \n", params[1], atoi(params[1]));
// 		printf("El resultado de mi atoi con este el string %s es %d ", params[1], ft_atoi(params[1]));
// 	}
// 	return (0);
// }
