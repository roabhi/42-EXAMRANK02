/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:44:04 by rabril-h          #+#    #+#             */
/*   Updated: 2023/01/10 21:07:15 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h> //Include printf
#include <stdlib.h> // Include malloc and NULL

/**
 * @brief 
 * 
 * This function takes care of determining how many digits
 * the passed nbr param has as integer so we know how many chars
 * we will need to hold that same int as a string
 * 
 * 5250 has 4 digits while -5250 has 5 digits
 * 
 * If the number is negative we directly add 1 to the count and
 * convert the number to positive so we can use the following loop
 * in which we keep adding digits to our count until number is no longer greater
 * than 0
 * 
 * we return the count 
 * 
 * 
 * @param nbr int - the number
 * @return int number of digits of number
 */

int	ft_get_longitude(int nbr)
{
	int c;

	c = 0;
	if (nbr < 0)
	{
		c++;
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		c++;
	}
	return (c);
}

/**
 * @brief 
 * 
 * This function reverses a string taking into account if the string has a minus sign
 * as first char.
 * 
 * If so we start our reversing at the next position. We use to indexes
 * 
 * start = either 0 or 1 if char has - sign
 * end = the longitude of the string determined by ft_get_longitude() - 1 char for the closing '\0' char
 * 
 * By using a temp var we just swap one char to the opposite in the string 
 * We increment start and reduce end so they get closer and closer each time so actually
 * the swap / loop only goes until half the lengh of the string
 * 
 * Then we return the result
 * 
 * @param str char *
 * @param longitude int
 * @return char* str
 */

char	*ft_strrev(char *str, int longitude)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = longitude - 1;
	if (str[start] == '-')
		start++;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

/**
 * @brief 
 * 
 * This exercice is the reverse of the atoi. We need to convert an int to a string
 * Also we need to allocate resulting string with malloc.
 * 
 * In order to do that we need to first know how many chars are needed for the reserve
 * Each char will hold a digit so basically we need to know how many digits we need to 
 * print and if the number is negative we also need to print out the sign
 * 
 * That is done in ft_get_longitude()
 * 
 * Once we allocate memory and after a few checks like
 * 1) number is 0 ? return just 0
 * 2) number is less than 0 ? then the first char will be a - sign. If so we need to convert the number to positive
 * because the conversion will be done using positibe numbers
 * 
 * For the conversion itself we keep going until de number is greater than 0
 * and we take the % of the vision, converting the result to char by doing
 * 
 * str[c] = (nbr % 10) + 48; 48 is the same as '0'
 * 
 * Then we divide the number by 10 and we keep going until number is NOT greater than 0
 * So for example for 5250
 * 
 * 5250 / 10 = 525.0 We take 0 as the result of module. Then we divide 5250 / 10 = 525
 * 525 / 10 = 52.5 We take 5 as the result of the module. Then we divide 525 / 10 = 52
 * 52 / 10 = 5.2 We take 2 as the result of the module. Then we dicide 52 / 10 = 5
 * 5 / 10 = 0.5 We take 5 as the result of the module. Then we divide 5 / 10 = 0.5
 * 
 * Number is no longer greater than 0 so we stop here.
 * 
 * our result so far is exactly the input int in string but reversed so for 5250 is 0525
 * 
 * finally we close the string by adding '\0' to the extra char reserver with malloc
 * 
 * The reverse operation is done using ft_strrev()
 * 
 * 
 * 
 * @param nbr int
 * @return char* 
 */


char	*ft_itoa(int nbr)
{
	char	*str;
	int		longitude;
	int		c;
	
	c = 0;
	longitude = ft_get_longitude(nbr);
	str = (char *)malloc(sizeof (char) * (longitude + 1));
	if (!str)
		return (NULL);
	if (nbr == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (nbr < 0)
	{
		str[c] = '-';
		nbr = nbr * -1;
		c++;
	}
	while (nbr > 0)
	{
		str[c] = (nbr % 10) + 48;
		nbr = nbr / 10;
		c++;
	}
	str[c] = '\0';
	str = ft_strrev(str, longitude);
	return(str);
}

// int main(void)
// {
// 	static int num = 1999;
// 	printf("el resultado de %i con mi itoa es %s",num, ft_itoa(num));    
// 	return (0);
// }
