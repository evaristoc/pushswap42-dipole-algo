/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:38:03 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/22 13:11:38 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
fills the first n bytes of the memory area pointed to by dest a len strip with \0
RETURNS:
- pointer to the memory area
- NULL if pointer is null
*/
void	ft_bzero(void *dest, size_t len)
{
	ft_memset(dest, 0, len);
}
