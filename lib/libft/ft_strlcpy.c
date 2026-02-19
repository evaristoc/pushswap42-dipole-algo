/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:28:54 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/31 20:21:46 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief copy string @p src up to length @p size in @p dest
* RETURNS
-- (dst string; NULL if size 0)
-- length of src represented by the highest @p index reached
 - to make truncation detection simple
* @warning the size of dest should be enough to accept the added
* characters coming from src
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (src[index] != '\0' && index < (size - 1))
	{
		dest[index] = src[index];
		++index;
	}
	dest[index] = '\0';
	return (ft_strlen(src));
}
