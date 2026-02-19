/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:23:04 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/22 13:11:47 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
check if alphanum (ascii)
RETURNS
-- 0 if false
-- 1 if true
*/
int	ft_isalnum(int c)
{
	return (ft_isdigit(c) != 0 || ft_isalpha(c) != 0);
}
