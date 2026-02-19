/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:35:52 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/30 21:10:22 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief applies the function @p func to each character 
 * of the string @p str, passing its index as the first 
 * argument and the character itself as the second. A new
 * string is created (using malloc) to store the 
 * results from the successive applications of func
 * @return string created from the successive applications of func.
 * @return NULL if the allocation fails.
 */
char	*ft_strmapi(char const *str, char (*func)(unsigned int, char))
{
	size_t	index;
	size_t	lenbuffer;
	char	*dest;

	if (!str || !func)
		return (NULL);
	lenbuffer = ft_strlen(str);
	dest = (char *)malloc((lenbuffer + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	index = 0;
	while (index < lenbuffer)
	{
		dest[index] = func(index, (str[index]));
		if (!dest)
		{
			free(dest);
			return (NULL);
		}
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
