/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:52:32 by gabtan            #+#    #+#             */
/*   Updated: 2023/05/01 16:49:06 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
			i--;
		}
		i++;
	}
	return (count);
}

static size_t	ft_get_stop(char *s, char c, int *start)
{
	size_t	stop;

	stop = *start;
	while (s[stop] != c && s[stop] != '\0')
		stop++;
	return (stop);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		index;
	int		start;
	size_t	stop;

	start = 0;
	index = 0;
	if (!s)
		return (NULL);
	array = (char **)ft_calloc(sizeof(char *), (ft_counter((char *)s, c) + 1));
	if (array == NULL)
		return (NULL);
	while (s[start] != '\0')
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		if (s[start] == '\0')
			break ;
		stop = ft_get_stop((char *)s, c, &start);
		array[index] = ft_substr(s, start, stop - start);
		index++;
		start = stop;
	}
	array[index] = 0;
	return (array);
}