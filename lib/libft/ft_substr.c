/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:12:40 by ecarabal          #+#    #+#             */
/*   Updated: 2025/11/02 17:19:19 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates memory (using malloc) and returns a 
 * substring from the string @p src ; the substring starts 
 * at index @p start and has a maximum number of char of str
 * of @p buffer
 * @param[in] src
 * @param[in] start
 * @param[in] buffer
 * @return (malloc) pointer of type *char
 * @warning owner frees
 */
char	*ft_substr(char const *src, unsigned int start, size_t subbuffer)
{
	char		*subpnt;
	size_t		maxbuffer;

	if (!src)
		return (NULL);
	maxbuffer = ft_strlen((char *)src);
	if (start >= maxbuffer)
		return (ft_strdup(""));
	if (start >= maxbuffer)
		subbuffer = 0;
	else if (subbuffer > maxbuffer - start)
		subbuffer = maxbuffer - start;
	subpnt = (char *)malloc((subbuffer + 1) * sizeof(char));
	if (!subpnt)
		return (NULL);
	ft_strlcpy(subpnt, src + start, subbuffer + 1);
	return (subpnt);
}
