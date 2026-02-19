/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:34:47 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/22 13:12:38 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
convert lower to upper
RETURNS
-- lower if alpha
*/
int	ft_toupper(int c)
{
	if (ft_islower(c))
	{
		c &= ~32;
	}
	return (c);
}
