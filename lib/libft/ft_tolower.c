/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:34:47 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/22 13:12:50 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
convert upper to lower
RETURNS
-- upper if alpha
*/
int	ft_tolower(int c)
{
	if (ft_isupper(c))
	{
		c |= 32;
	}
	return (c);
}
