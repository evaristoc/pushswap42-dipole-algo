/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:24:57 by ecarabal          #+#    #+#             */
/*   Updated: 2025/11/28 20:47:35 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief allocates memory (using malloc) and returns 
 * a string @p dest representing the integer @p n received as an 
 * argument. Negative numbers must be handled.
 * This is a while-loop implementation
 * The assigment from integer to char is done in reverse
 * @param[in] n
 * @param[out] dest
 */
char	*ft_itoa(int n)
{
	char	*dest;
	long	nb;
	int		itoabuffer;

	nb = n;
	itoabuffer = ft_numlen(nb, 10);
	dest = (char *)malloc((itoabuffer + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[itoabuffer] = '\0';
	if (nb == 0)
		dest[0] = '0';
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		dest[--itoabuffer] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
