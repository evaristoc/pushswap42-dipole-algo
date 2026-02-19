/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:24:02 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/31 20:27:51 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief only compares the first (at most) @p n bytes of 
 * two strings @p comp and @p agnst
RETURN
- integer less than, equal to, or greater than zero if 
  comp is found, respectively, to be
  less than, to match, or be greater than against
*/
int	ft_strncmp(const char *comp, const char *agnst, size_t n)
{
	size_t	i;

	i = 0;
	while ((comp[i] || agnst[i]) && i < n)
	{
		if ((unsigned char) comp[i] != (unsigned char) agnst[i])
			return ((unsigned char) comp[i] - (unsigned char) agnst[i]);
		i++;
	}
	return (0);
}
