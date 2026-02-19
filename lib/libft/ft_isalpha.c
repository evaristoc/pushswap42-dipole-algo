/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:15:15 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/22 12:56:05 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
check if alpha
RETURNS
-- 0 if false
-- 1 if true
*/
int	ft_isalpha(int c)
{
	return (ft_islower(c) != 0 || ft_isupper(c) != 0);
}
