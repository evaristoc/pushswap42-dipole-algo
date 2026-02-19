/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:52:22 by ecarabal          #+#    #+#             */
/*   Updated: 2025/11/01 19:57:17 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief applies the function @p func to each character of 
 * the string @p str passed as argument, passing its index as 
 * the first argument. @p func gets the pointer (ref) of
 * character @p str[index] so it can be modified if necessary
 * @return new string created from the successive applications of @p func.
 * @return NULL if the allocation fails.
 */
void	ft_striteri(char *str, void (*func)(unsigned int, char*))
{
	size_t	index;

	if (!str)
		return ;
	index = 0;
	while (str[index])
	{
		(*func)(index, &(str[index]));
		index++;
	}
}
