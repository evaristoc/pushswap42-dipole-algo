/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:26:00 by ecarabal          #+#    #+#             */
/*   Updated: 2025/11/01 20:21:39 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
copies n bytes from memory area src to memory area dest;
the memory areas may overlap: copying takes place as though the bytes
in src are first copied into a temporary array that does not overlap src 
or dest, and the bytes are then copied from the temporary array to dest
RETURN
- returns a pointer to dest
OBS:
- requires casting because voids can not be worked?
* @warning acts on second pointers to sources to keep 
* entering pointers unmoved and uncasted
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				index;
	unsigned char		*destpnt;
	const unsigned char	*srcpnt;

	index = n;
	destpnt = (unsigned char *)dest;
	srcpnt = (const unsigned char *)src;
	if ((srcpnt < destpnt) && srcpnt + n > destpnt)
	{
		while (index--)
		{
			*(destpnt + index) = *(srcpnt + index);
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
