/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:58:29 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/22 13:13:24 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
compares the two strings comp and against
RETURN
- integer less than, equal to, or greater than zero if comp 
	is found, respectively, to be
	less than, to match, or be greater than against
*/
int	ft_strcmp(const char *comp, const char *against)
{
	int	index;

	index = 0;
	while (comp[index] == against[index] && comp[index] != '\0')
	{
		index++;
	}
	return (comp[index] - against[index]);
}
