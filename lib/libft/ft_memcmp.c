/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:16:40 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/28 19:13:38 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare the first @p `n` bytes of @p `comp` and @p `against`.
 * @param[in] comp		First pointer to compare
 * @param[in] against	Second pointer to compare
 * @param[in] n			Amount of bytes to compare
 * @retval 0 if @p `comp` and @p `against` are equal
 * @retval negative if comp is smaller than against.
 * @retval positive if comp is bigger then against.
 */
int	ft_memcmp(const void *comp, const void *against, size_t n)
{
	size_t			index;
	unsigned char	*cmppnt;
	unsigned char	*agtpnt;

	cmppnt = (unsigned char *)(comp);
	agtpnt = (unsigned char *)(against);
	index = 0;
	if (n == 0)
	{
		return (0);
	}
	while (index < n && (*cmppnt == *agtpnt))
	{
		index++;
		if (*cmppnt != *agtpnt || index == n)
		{
			return (*(cmppnt - 1) - *(agtpnt - 1));
		}
		cmppnt++;
		agtpnt++;
	}
	return (*cmppnt - *agtpnt);
}
