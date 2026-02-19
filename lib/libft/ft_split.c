/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarabal <ecarabal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:16:34 by ecarabal          #+#    #+#             */
/*   Updated: 2025/10/29 20:21:24 by ecarabal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief a general function to free @p arr when filled with
 * at least @p filled elements
 * @param[in] arr
 * @param[in] filled
 * @return void
 */
static void	free_all(char **arr, size_t filled)
{
	while (filled > 0)
	{
		free(arr[--filled]);
	}
	free(arr);
}

/**
 * @brief find the next valid sub-string in @p src guided by 
 * @p delimiter character, and pass that substring as a 
 * dynamically allocated value
 * it use the ft_substr function to allocate the substring
 * @param[in] scr
 * @param[in] delimiter
 * @return a dynamically allocated substring from @p src
 * @return NULL if not able to get a string
 */
static char	*get_str_elem(char const *src, char delimiter)
{
	char const	*end;

	end = src;
	while (*end && *end != delimiter)
	{
		end++;
	}
	if (*src)
		return (ft_substr(src, 0, end - src));
	else
		return (NULL);
}

/**
 * @brief first pass - counting the number of strings after every found
 * of @p delimiter until getting the end of the @p src string
 * @param[in] src
 * @param[in] delimiter
 * @return number of substrings + 1
 */
static int	pass1_getstrcount(char const *src, char delimiter)
{
	size_t		count;
	int			in_str;
	char		*p;

	count = 0;
	in_str = 0;
	p = (char *)src;
	while (*p)
	{
		if (*p != delimiter && !in_str)
		{
			in_str = 1;
			count++;
		}
		else if (*p == delimiter)
			in_str = 0;
		p++;
	}
	return (count);
}

/**
 * @brief second pass - visit the string again to get the strings
 * and assign them to their corresponding location in the array;
 * it uses the array @p arr , a pointer to the source 
 * as @p p , the delimiter character @p delimit and the 
 * number of identified
 * strings, @p counted_strs
 * @param[in] arr
 * @param[in] p
 * @param[in] delimit
 * @param[in] counted_strs
 * @return array of substrings
 * @return NULL if not able to allocate, after freeing the 
 * existing allocation
 * @warning @p p position is moved!
 */
static char	**pass2_getarr(char **arr, char const *p, char dlt, size_t counted)
{
	size_t	fill;

	fill = counted;
	while (*p)
	{
		if (*p != dlt)
		{
			arr[counted - fill] = get_str_elem(p, dlt);
			if (!arr[counted - fill])
				return (free_all(arr, counted - fill), NULL);
			p = p + ft_strlen(arr[counted - fill]);
			fill--;
			if (fill == 0)
			{
				arr[counted] = NULL;
				break ;
			}
		}
		p++;
	}
	return (arr);
}

/**
 * @brief allocates memory (using malloc) and returns an 
 * array of strings obtained by splitting the string @p src 
 * using the character @p delimit as a delimiter.
 * The array must end with a NULL pointer.
 * This function is a controller that runs other 
 * static functions
 * @param[in] src
 * @param[in] delimit
 * @return dynamic array of substrings if correct
 * @return NULL if unable to allocate values
 */
char	**ft_split(char const *src, char delimit)
{
	char		**arr;
	int			counted_strs;
	char const	*srcpnt;

	srcpnt = src;
	if (!srcpnt)
		return (NULL);
	counted_strs = pass1_getstrcount(srcpnt, delimit);
	arr = ft_calloc(counted_strs + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	return (pass2_getarr(arr, srcpnt, delimit, counted_strs));
}
