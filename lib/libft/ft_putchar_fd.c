/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:36:53 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/29 18:15:24 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief outputs character @p c to the specified file
descriptor @p fd
@param[in] c
@param[in] fd
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
