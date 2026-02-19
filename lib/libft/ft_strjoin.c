/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:24:00 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/29 18:17:30 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief allocates memory (using malloc) and returns 
 * a new string which is the result of concatenating @p prefstr 
 * and @p ssuffstr
 * it first copy prefix prefstr into @p dest , and then concact
 * suffix ssuffstr to what has been copied into dest
 * @param[in] prefstr (prefix)
 * @param[in] suffstr (suffix)
 * @return dest string
 * @param[out] dest
 * @warning owner must free
 */
char	*ft_strjoin(char const *prefstr, char const *suffstr)
{
	char	*dest;
	size_t	lenprefstr;
	size_t	lensuffstr;
	size_t	destbuffer;

	if (!prefstr || !suffstr)
		return (NULL);
	lenprefstr = ft_strlen((char *)prefstr);
	lensuffstr = ft_strlen((char *)suffstr);
	destbuffer = lenprefstr + lensuffstr + 1;
	dest = (char *)malloc(destbuffer * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, prefstr, lenprefstr + 1);
	ft_strlcat(dest, suffstr, destbuffer);
	return (dest);
}
