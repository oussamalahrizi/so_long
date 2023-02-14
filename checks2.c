/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:13:48 by olahrizi          #+#    #+#             */
/*   Updated: 2023/02/14 23:24:31 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lines(char **map)
{
	int	c;

	c = 0;
	while (*map)
	{
		c++;
		map++;
	}
	return (c);
}

int	check_collectible(char **map)
{
	int	i;
	int	c;
	int	j;

	c = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				c++;
			i++;
		}
		j++;
	}
	if (!c)
	{
		ft_printf("collectible\n");
		return (0);
	}
	return (1);
}

int	helper(int p, int e)
{
	if (!p || p > 1 || !e || e > 1)
	{
		ft_printf("player or exit\n");
		return (0);
	}
	return (1);
}

void	mapping(t_data *data, int *p, int *e, int j)
{
	int	i;

	i = 0;
	while (data->map[j][i])
	{
		if (data->map[j][i] == 'P')
		{
			data->pos_player.x = i;
			data->pos_player.y = j;
			(*p)++;
		}
		else if (data->map[j][i] == 'E')
			(*e)++;
		i++;
	}
}

int	check_player_exit(t_data *data)
{
	int	i;
	int	p;
	int	e;
	int	j;

	p = 0;
	e = 0;
	j = 0;
	while (data->map[j])
	{
		i = 0;
		mapping(data, &p, &e, j);
		j++;
	}
	if (!helper(p, e))
		return (0);
	return (1);
}
