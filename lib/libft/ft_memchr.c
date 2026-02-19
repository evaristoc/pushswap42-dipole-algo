/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:53:03 by ecarabal          #+#    #+#             */
/*   Updated: 2025/11/01 19:55:14 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
* @brief scans the initial n bytes of the memory area pointed to by dest 
for the first instance of c; both c and the bytes of the memory 
area pointed to by s are interpreted as **unsigned char**
RETURN
- pointer to the matching byte
- NULL if the character does not occur in the given memory area
* @warning acts on second pointers to sources to keep 
* entering pointers unmoved and uncasted
*/
void	*ft_memchr(const void *dest, int c, size_t n)
{
	int				index;
	unsigned char	*destpnt;

	index = 0;
	destpnt = (unsigned char *)dest;
	while (index < (int)n)
	{
		if (*(destpnt + index) == (unsigned char)c)
		{
			return ((void *)(destpnt + index));
		}
		index++;
	}
	return (NULL);
}
