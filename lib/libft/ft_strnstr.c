/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:39:51 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/29 20:58:08 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
find a string inside another string only up to length len
if last characters of string match and there are still characters completing
the match beyond len, then the match is also valid
RETURNS
-- NULL if segment string not found
-- pointer of first occurrence if found
*/
char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	n;

	if (*nee == 0)
		return ((char *)hay);
	n = ft_strlen(nee);
	while (*hay && n <= len)
	{
		if (*hay == *nee && ft_strncmp((char *)hay, (char *)nee, n) == 0)
			return ((char *)hay);
		++hay;
		--len;
	}
	return (NULL);
}
