/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:52:38 by ecarabal          #+#    #+#             */
/*   Updated: 2025/11/02 15:48:46 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief allocates memory for an array of @p nmemb elements 
 * of @p size bytes each and returns a pointer to 
 * the allocated memory. The memory is set to ZEROs (use bzero)
 * @param[in] nmemb
 * @param[in] size
 * @return pointer if @p size and @p nmemb > 0
 * @return NULL 
 * @return unique 0 pointer if or zero of entering params
 * @warning owner free memory
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb >= (SIZE_MAX / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
