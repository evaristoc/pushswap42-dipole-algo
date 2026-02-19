/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:10:21 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/31 20:08:10 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief allocates memory (using malloc) and returns a  copy of @p str 
 * with characters from @p set removed from the beginning and the end.
 * @param[in] str
 * @param[in] set
 */
char	*ft_strtrim(char const *str, char const *set)
{
	char const	*strpnt;
	size_t		trimbuffer;

	strpnt = str;
	if (!str || !set)
		return (NULL);
	if (ft_strlen(str) == 0)
		return (ft_strdup(""));
	while (*strpnt && (ft_strchr(set, *strpnt)))
		strpnt++;
	trimbuffer = ft_strlen(strpnt);
	while (trimbuffer && (ft_strchr(set, *(strpnt + trimbuffer))))
		trimbuffer--;
	if (*strpnt)
		return (ft_substr(strpnt, 0, trimbuffer + 1));
	else
		return (ft_strdup(""));
}
