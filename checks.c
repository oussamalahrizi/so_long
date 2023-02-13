/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:00:22 by Exiled            #+#    #+#             */
/*   Updated: 2023/02/13 13:00:22 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_new_lines(char *map)
{
	int	i;

	i = 0;
	if (map[0] == '\n' || map[ft_strlen(map) - 1] == '\n')
		return (0);
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check_rectangle(char **map)
{
	int	i;
	int	len;
	int	temp;
	int	not;

	i = 0;
	not = 0;
	len = ft_strlen(*map);
	temp = 0;
	while (map[i])
	{
		temp = ft_strlen(map[i]);
		if (temp != len)
		{
			not = 1;
			break ;
		}
		i++;
	}
	if (not)
	{
		ft_printf("not rectangle\n");
		return (0);
	}
	return (1);
}

int	check_walls_helper(char **map)
{
	int		i;
	int		c;
	char	**temp;

	i = 0;
	temp = map;
	c = map_lines(map);
	while (temp[0][i] == '1')
		i++;
	if (i != ft_strlen(temp[0]))
	{
		ft_printf("extern walls 1\n");
		return (0);
	}
	i = 0;
	while (temp[c - 1][i] == '1')
		i++;
	if (i != ft_strlen(temp[c - 1]))
	{
		ft_printf("extern walls 2\n");
		return (0);
	}
	return (1);
}

int	check_extern_walls(char **map)
{
	int	i;
	int	not;

	if (!check_walls_helper(map))
		return (0);
	not = 0;
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(*map) - 1] != '1')
		{
			not = 1;
			break ;
		}
		i++;
	}
	if (not)
	{
		ft_printf("extern walls 3\n");
		return (0);
	}
	return (1);
}

int	check_imposter(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'C'
				&& map[j][i] != 'P' && map[j][i] != 'E')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
