/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:03:31 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/29 18:06:36 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief outputs each character of string @p str to 
 * the specified file descriptor @p fd
 * @param[in] str
 * @param[in] fd
 */
void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
