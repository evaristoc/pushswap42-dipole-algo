/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:56:00 by ecarabal          #+#    #+#             */
/*   Updated: 2025/11/01 20:37:57 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief returns a pointer to a new string which is a duplicate of
 * the string @p str.
 * Memory for the new string is obtained with malloc and 
 * can be freed with free
 * @param[in] str
 * @return duplication of @p str as @p dest in dynamic mem
 * @warning onwer free memory
 */
char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	dupbuffer;
	size_t	index;

	dupbuffer = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (dupbuffer + 1));
	if (!dest)
	{
		return (NULL);
	}
	index = 0;
	while (index < dupbuffer)
	{
		dest[index] = str[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
