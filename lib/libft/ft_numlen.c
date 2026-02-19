/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:53:26 by ecarabal          #+#    #+#             */
/*   Updated: 2025/12/06 19:59:25 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief calculate the number of bytes (buffer) required for 
 * the string conversion that represents the @p n 
 * integer. Includes the negative sign if exists
 */
int	ft_numlen(long n, int base)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}
