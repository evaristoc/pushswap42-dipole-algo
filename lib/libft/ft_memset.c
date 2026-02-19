/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:49:17 by ecarabal          #+#    #+#             */
/*   Updated: 2025/11/01 19:54:19 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief fills the first n bytes of the memory area pointed 
* to by @p dest a @p len strip with the constant byte @p ch
RETURNS:
- pointer to the memory area
- NULL if pointer is null
* @warning acts on destpnt to keep dest unmoved and uncasted
*/
void	*ft_memset(void *dest, int ch, size_t len)
{
	unsigned char	*destpnt;
	unsigned char	c;
	size_t			n;

	destpnt = (unsigned char *)dest;
	c = (unsigned char)ch;
	n = len;
	while (n > 0)
	{
		*destpnt = c;
		destpnt++;
		n--;
	}
	return (dest);
}
