/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:23:38 by Exiled            #+#    #+#             */
/*   Updated: 2023/02/16 13:23:38 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player_helper(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_enemies)
		if (is_within_range(data->enemies[i],
				data->player_x, data->player_y, 25))
			ft_exit("you lost\n", data);
	mlx_clear_window(data->mlx, data->win);
	set_map(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->player, data->player_x, data->player_y);
}

void	move_player(t_data *data)
{
	int	target_x;
	int	target_y;
	int	i;

	target_x = data->pos_player.x * 50;
	target_y = data->pos_player.y * 50;
	if (data->player_x > target_x)
	{
		data->player_x += -data->speed;
		data->player = data->player_left;
	}
	else if (data->player_x < target_x)
	{
		data->player_x += data->speed;
		data->player = data->player_right;
	}
	if (data->player_y > target_y)
		data->player_y += -data->speed;
	else if (data->player_y < target_y)
		data->player_y += data->speed;
	move_player_helper(data);
}

int	valid_position(t_data *data, int x, int y)
{
	int	i;

	if (data->map[y][x] == '1' || data->map[y][x] == 'E'
		|| data->map[y][x] == 'C')
		return (0);
	i = 0;
	while (i < data->num_enemies)
	{
		if (data->enemies[i].map_x == x && data->enemies[i].map_y == y)
			return (0);
		i++;
	}
	return (1);
}
