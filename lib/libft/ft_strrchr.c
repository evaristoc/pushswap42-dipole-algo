/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:44:35 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/31 20:20:49 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief finds the last occurrence of the char ch in the string target
 * the terminating '\0' characters are not compared <-- !!!CHECK THIS
RETURN
- if found, a pointer to the matched character
- NULL if the character is not found
- NULL if ch = aq\0aq (the terminating null byte) and pointer to the terminator
* @warning my reverse implementation is said to be slightly faster
*          but depends: I have two while loops (incl. ft_strlen)
* @warning based on a classmate code to cope with a single error in
* 		   francinette I couldn't solve using my backward sol
*/
char	*ft_strrchr(const char *target, int ch)
{
	size_t	i;
	char	*dest;
	char	cc;

	i = 0;
	dest = NULL;
	cc = (char)ch;
	while (target[i])
	{
		if (target[i] == cc)
			dest = (char *)&target[i];
		i++;
	}
	if (target[i] == cc)
		dest = (char *)&target[i];
	return (dest);
}
