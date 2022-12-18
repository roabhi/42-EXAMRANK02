/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:24:33 by rabril-h          #+#    #+#             */
/*   Updated: 2022/12/18 19:37:43 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h> // include strpbrk
// #include <stdio.h> // include printf

/**
 * @brief 
 * 
 * Similar to strcspn but with pointers instead of simple char values
 * 
 * The key here is to understand how pointers work since they just
 * reference a specific point in memory. In this case some memory
 * space assigned to hold a char from a string
 * 
 * When we see * as part of the function name we know
 * where are going to return a reference to memory
 * in this case a pointer to s1 where the first occurrence happens compared 
 * to the s2 char set passed as params as well.
 * 
 * What we will return then will be the remaining chars from s1 up to its end
 * 
 * So for example
 * 
 * s1 = "abcde2fghi3jk4l"
 * s2 = "34"
 * 
 * The first occurrence is going to happen at 3 since 3 is included in s1
 * before 4. 
 * 
 * That means that the return value will be a ponter to "abcde2fghi(&3)jk4l"
 * resulting in a print of 3jk4l from printf since that is
 * the reference we return as we find that first occurrence between s1 and chars from s2
 * 
 * Note: The return value needs to be casted with (char *)&s1[c] because we are using s1[c]
 * and not just *s1 to go through s1.
 * 
 * the loops could have been like so as well
 * 
 * while (*s1)
 * {
 * 		j = 0;
 * 		while (s2[j])
 * 		{
 * 			if(*s1 == s2[i])
 * 				return ((char *)s1)
 * 			j++;
 * 		}
 * 		s1++;
 * }
 * return (0);
 * 
 * That is because referencing a str as pointer already has a built in length
 * and we can go through it as we move just the pointer from the char at index 0 to index 1 ... and so on
 * until s1 is null terminated
 * 
 * On the other hand it seems we need to thread s2 loop always using s2[counter] and we cannot
 * compare just *s1 == *s2 using poiter increments like so. No fucking clue why. 
 * 
 * The following DOES NOT WORK
 * 
 *	while(*s1)
 *	{
 *	   	while(*s2)
 *		{
 *			if(*s1 == *s2)
 *				return (char *) s1;
 *			s2++;
 *		}
 *		s1++;	
 *	}
 *	return (0);
 *
 *  Note: if not match is found we just return (0) or NULL
 *  return(0) is equivalent to return (NULL) but we need to include string.h to use NULL
 * 	
 * @param s1 const char *
 * @param s2 const char *
 * @return char* 
 */

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	c;
	int	j;

	c = 0;
	while (s1[c])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[c] == s2[j])
				return ((char *)&s1[c]);
			j++;
		}
		c++;
	}
	return (0);
}

// int main(void)
// {
// 	static char str[] = "abcde2fghi3jk4l";
// 	static char set[] = "34";
// 	printf("\nLa primera coincidencia en %s de %s con strpbrk del sistema es %s\n", str, set, strpbrk(str, set));
// 	printf("La primera coincidencia en %s de %s con mi ft_strpbrk del sistema es %s", str, set, ft_strpbrk(str, set));   
// 	return (0);
// }
