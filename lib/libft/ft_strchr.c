/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:58:11 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/30 15:19:09 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
@brief find char occurrence inside another string
RETURNS
-- NULL if not found
-- pointer of first occurrence if found
@return also handles if the value of c is \0
@todo check why it is no using Doxigen
*/
char	*ft_strchr(const char *str, int c)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == (char)c)
		{
			return ((char *)&str[index]);
		}
		++index;
	}
	if (str[index] == (char)c)
	{
		return ((char *)&str[index]);
	}
	else
	{
		return (NULL);
	}
}
