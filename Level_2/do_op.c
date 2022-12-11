/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:21:58 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/11 19:52:31 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


/*
Here we use prinf for the first time in the EXAMRANK exercices
as well as atoi (inbuild system function to convert strings to numebers)
so we need to import stdio stdlib libraries for each one respectively

The tricky part is to figure out how to treat the operator 
meaning how to convert a (char) param into an operator.
Don' t.
We only accept 4 operator / cases so make an if statement for each case 
then use the operator from system an atoi to get the result for each case

It is importat to look at first position inside params[2] with params[2][0]
otherwise we would be comparing char * (the pointer we the param[2] starts) and int. 
we are looking to compare char and int
*/


int	main(int i, char **params)
{
	if (i == 4)
	{
		if (params[2][0] == '+')
			printf("%d", atoi(params[1]) + atoi(params[3]));
		else if (params[2][0] == '-')
			printf("%d", atoi(params[1]) - atoi(params[3]));
		else if (params[2][0] == '*')
			printf("%d", atoi(params[1]) * atoi(params[3]));
		else if (params[2][0] == '/')
			printf("%d", atoi(params[1]) / atoi(params[3]));
		else if (params[2][0] == '%')
			printf("%d", atoi(params[1]) % atoi(params[3]));
	}
	printf("\n");
	return (0);
}
