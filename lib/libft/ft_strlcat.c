/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:00:07 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/29 17:54:12 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief concat string @p str2concat up to length @p finalsize 
* in @p dest
* the function:
* -- find len of dest while i < @p finalsize
* -- if no null value found during that transverse, the position
*    is set to be @p finalsize
* then:
* -- if no null terminated src and the current len (<= lendest),
*    j + 1 always smaller than the @p finalsize , concat!
*
* start position is the length of dest, concat happens 
* up to length finalsize, which should include the size of 
* dest to accomodate the concat
* RETURNS
-- (modified dst string; dest if size = 0)
-- length of src + dest - to make truncation detection simple
* @warning dest should have enough memory buffer to accept 
* the added characters coming from str2concat
* @warning if size is larger than the sizes of dest and src + terminator
* the concatenation is truncated 
*/
size_t	ft_strlcat(char *dest, const char *str2concat, size_t finalsize)
{
	size_t	lendes;
	size_t	lensrc;

	lendes = 0;
	while (dest[lendes] != '\0' && lendes < finalsize)
	{
		lendes++;
	}
	lensrc = 0;
	while (str2concat[lensrc] != '\0' && (lendes + lensrc + 1) < finalsize)
	{
		dest[lendes + lensrc] = str2concat[lensrc];
		lensrc++;
	}
	if ((lendes + lensrc) < finalsize)
	{
		dest[lendes + lensrc] = '\0';
	}
	while (str2concat[lensrc] != '\0')
	{
		++lensrc;
	}
	return (lendes + lensrc);
}
