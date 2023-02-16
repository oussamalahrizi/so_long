/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:21:12 by Exiled            #+#    #+#             */
/*   Updated: 2023/02/16 13:21:12 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	quit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("you exited the game.\n");
	exit(1);
	return (0);
}

int	key_hook(int e, t_data *data)
{
	int	collectible_count;

	collectible_count = count_collect_exit(data->map, 'C');
	if (e == 126)
		go_up(data, collectible_count);
	else if (e == 123)
		go_left(data, collectible_count);
	else if (e == 125)
		go_down(data, collectible_count);
	else if (e == 124)
		go_right(data, collectible_count);
	else if (e == 53)
		quit(data);
	return (0);
}

void	draw_enemy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_enemies)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->enemies[i].enemy,
			(data->enemies[i].x / 50) * 50, (data->enemies[i].y / 50) * 50);
		i++;
	}
}

int	is_within_range(t_enemy_can enemy, int x, int y, int size)
{
	int	distance_x;
	int	distance_y;

	distance_x = abs(x - enemy.x);
	distance_y = abs(y - enemy.y);
	if (distance_x <= size && distance_y <= size)
		return (1);
	return (0);
}

void	ft_exit(char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
	exit(1);
}
