/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:14:27 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/18 11:02:55 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	get_total_words(char *str, char c)
{
	size_t	_string_count;

	_string_count = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			_string_count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (_string_count);
}

char	**free_stuff(char **strings)
{
	size_t	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		strings[i] = NULL;
		i++;
	}
	free(strings);
	strings = NULL;
	return (strings);
}

size_t	get_len(char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char	**ft_split(char *s, char c)
{
	char	**strings;
	size_t	index;

	if (!s)
		return (NULL);
	strings = (char **) malloc(sizeof(char *) * (get_total_words(s, c) + 1));
	if (!strings)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			strings[index++] = ft_substr(s, 0, get_len(s, c));
			if (!strings[index - 1])
				return (free_stuff(strings));
			s += get_len(s, c);
		}
	}
	strings[index] = 0;
	return (strings);
}