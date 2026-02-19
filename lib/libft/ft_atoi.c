/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:08:47 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/31 20:19:06 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief converts the initial portion of the string pointed 
 * to by @p nptr to @p int
 * @retval not overflow int
 * @warning care of integer overflow using long
 */
int	ft_atoi(const char *nptr)
{
	int		n;
	int		sign;
	size_t	index;

	index = 0;
	sign = 1;
	n = 0;
	if (!*nptr)
		return (0);
	while (ft_strchr(" \t\v\n\r\f", nptr[index]) != NULL)
		index++;
	if (nptr[index] == 43 || nptr[index] == 45)
	{
		sign *= '+' - (unsigned char)nptr[index] + 1;
		index++;
	}
	if (!ft_isdigit(nptr[index]))
		return (0);
	while (ft_isdigit(nptr[index]))
	{
		n = n * 10 + (nptr[index] - '0');
		index++;
	}
	return (sign * n);
}
