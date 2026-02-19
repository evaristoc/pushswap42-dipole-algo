/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:03:20 by ecarabal          #+#    #+#             */
/*   Updated: 2025/11/02 16:23:18 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief copies @p len bytes from memory area @p src to memory area @p dest ;
 * the memory areas must not overlap == should be different pointers in 
 * memory it appears to overwrite what it is in memory
RETURN
- returns a pointer to dest
* @warning acts on second pointers to sources to keep 
* entering pointers unmoved and uncasted
*/
void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t				lencpy;
	unsigned char		*destpnt;
	const unsigned char	*srcpnt;

	if (dest == src)
		return (dest);
	destpnt = (unsigned char *)(dest);
	srcpnt = (const unsigned char *)(src);
	lencpy = len;
	while (lencpy--)
	{
		*destpnt = *srcpnt;
		destpnt++;
		srcpnt++;
	}
	return (dest);
}
