/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:21:43 by ecarabal          #+#    #+#             */
/*   Updated: 2025/11/02 15:53:52 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief outputs the integer @p n to the specified file descriptor
 * @p fd
 */
void	ft_putnbr_fd(int n, int fd)
{
	long	dig;

	dig = n;
	if (dig < 0)
	{
		ft_putchar_fd('-', fd);
		dig = -dig;
	}
	if (dig >= 10)
	{
		ft_putnbr_fd(dig / 10, fd);
		ft_putchar_fd((dig % 10) + '0', fd);
	}
	else
		ft_putchar_fd(dig + '0', fd);
}
