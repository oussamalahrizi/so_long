/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:23:37 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/18 11:37:20 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(t_data *data, t_pos pos, char new, char imposter)
{
	if (pos.x < 0 || pos.y < 0 || pos.y >= data->map_count
		|| pos.x >= ft_strlen(data->holder[0]) || data->holder[pos.y][pos.x] == new)
		return ;
	if (data->holder[pos.y][pos.x] == '1' || data->holder[pos.y][pos.x] == imposter)
		return ;
	data->holder[pos.y][pos.x] = new;
	pos.y--;
	fill(data, pos, new, imposter);
	pos.y += 2;
	fill(data, pos, new, imposter);
	pos.y--;
	pos.x--;
	fill(data, pos, new, imposter);
	pos.x +=2;
	fill(data, pos, new, imposter);
}

void	flood_fill(t_data *data, t_pos pos, char c, char imposter)
{
	if (data->holder[pos.y][pos.x] == c)
		return ;
	fill(data, pos, c, imposter);
}

int	count_collect_exit(char **holder, char c)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (holder[y])
	{
		x = 0;
		while (holder[y][x])
		{
			if (holder[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	check_map(t_data *data)
{
	flood_fill(data, data->pos_player, 'H', 'E');
	if (count_collect_exit(data->holder, 'C'))
	{
		write(2, INVALID_PATH_C, ft_strlen(INVALID_PATH_C));
		exit(1);
	}
	flood_fill(data, data->pos_player, 'Q', '1');
	if (count_collect_exit(data->holder, 'E'))
	{
		write(2, INVALID_PATH_E, ft_strlen(INVALID_PATH_E));
		exit(1);
	}
}
