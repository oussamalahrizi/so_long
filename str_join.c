/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:08:53 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/18 11:02:55 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*result;
	size_t	i;
	size_t	n;

	if (nelem && elsize > SIZE_MAX / nelem)
		return (0);
	result = malloc(nelem * elsize);
	if (!result)
		return (0);
	i = 0;
	n = nelem * elsize;
	while (i < n)
	{
		*((unsigned char *)result + i) = 0;
		i++;
	}
	return (result);
}

char	*str_copy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*str_join(char *s1, char *s2)
{
	char *join;
	char *start;

	if (!s1)
		s1 = (char *)ft_calloc(1, 1);
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	start = join;
	join = str_copy(join, s1);
	join += ft_strlen(s1);
	join = str_copy(join, s2);
	join += ft_strlen(s2);
	*join = 0;
	free(s1);
	return (start);
}