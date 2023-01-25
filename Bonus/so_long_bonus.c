/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:45:42 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/25 23:42:11 by olahrizi         ###   ########.fr       */
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
int	is_within_range(int x1, int y1, int x2, int y2, int size);
void	move_player(t_data *data)
{
	int	target_x;
	int	target_y;

	target_x = data->pos_player.x * 50;
	target_y = data->pos_player.y * 50;
	if (data->player_x > target_x)
	{
		data->player = data->player_left;
		data->player_x += -data->speed;
	}
	else if (data->player_x < target_x)
	{
		data->player = data->player_right;
		data->player_x += data->speed;
	}
	if (data->player_y > target_y)
		data->player_y += -data->speed;
	else if (data->player_y < target_y)
		data->player_y += data->speed;
	for (int i = 0; i < data->num_enemies; i++)
	{
		if (is_within_range((int)data->enemies[i].x, (int)data->enemies[i].y, data->player_x, data->player_y, 25))
		{
			printf("you lost\n");
			exit(1);
		}
	}
	mlx_clear_window(data->mlx, data->win);
	set_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_x,
			data->player_y);
}

int	is_within_range(int x1, int y1, int x2, int y2, int size)
{
	int	distance_x;
	int	distance_y;

	distance_x = abs(x2 - x1) ;
	distance_y = abs(y2 - y1);
	if (distance_x <= size && distance_y <= size)
		return (1);
	return (0);
}
int	valid_position(t_data *data, int x, int y)
{
	if (data->map[y][x] == '1' || data->map[y][x] == 'E' || data->map[y][x] == 'C')
	{
		// printf("there is : %c\n", data->map[y][x]);
		return (0);
	}
	for (int i = 0; i < data->num_enemies; i++)
	{
		if (data->enemies[i].map_x == x && data->enemies[i].map_y == y)
			return (0);
	}
	return (1);
}

void	move_enemy_2(int target_x, int target_y, t_data *data, int index)
{
	if (data->enemies[index].x < target_x)
	{
		data->enemies[index].x += 2.5;
		data->enemies[index].enemy = data->enemy_right;
	}
	else if (data->enemies[index].x > target_x)
	{
		data->enemies[index].x -= 2.5;
		data->enemies[index].enemy = data->enemy_left;
	}
	if (data->enemies[index].y < target_y)
			data->enemies[index].y += 2.5;
	else if (data->enemies[index].y > target_y)
		data->enemies[index].y -= 2.5;
}

void	move_enemy(t_data *data)
{
	int	player_x;
	int	player_y;
	int	i;
	int	target_x;
	int	target_y;

	player_x = data->player_x;
	player_y = data->player_y;
	i = 0;
	while (i < data->num_enemies)
	{
		target_x = data->enemies[i].x;
		target_y = data->enemies[i].y;

		if (target_x - data->enemies[i].map_x * 50 || target_y - data->enemies[i].map_y * 50)
		{
			move_enemy_2(data->enemies[i].map_x * 50, data->enemies[i].map_y * 50, data, i);
			i++;
			continue;
		}
		if (target_x != player_x)
		{
			int dir = (player_x - target_x) > 0 ? 1 : -1;
			if (valid_position(data, data->enemies[i].map_x + dir, data->enemies[i].map_y))
				data->enemies[i].map_x += dir;
		}
		else if (target_y != player_y)
		{
			int dir = (player_y - target_y) > 0 ? 1 : -1;
			if (valid_position(data, data->enemies[i].map_x, data->enemies[i].map_y + dir))
				data->enemies[i].map_y += dir;
		}
		i++;
	}
}

#include <time.h>
int	listener(t_data *data)
{
	clock_t t = clock();
	move_player(data);
	move_enemy(data);
	draw_enemy(data);

	clock_t curr = clock();
	while ((double)(curr - t) / CLOCKS_PER_SEC < 1.0 / 120)
		curr = clock();
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (ac != 2)
	{
		write(2, INVALID_ARGS, ft_strlen(INVALID_ARGS));
		exit(1);
	}
	if (ft_strncmp(".ber", av[1] + ft_strlen(av[1]) - 4, 4))
	{
		write(2, INVALID_EXT, ft_strlen(INVALID_EXT));
		exit(1);
	}
	data.map_path = av[1];
	init_stuff(&data, 1);
	init_map(&data);
	set_map(&data);
	check_map(&data);
	i = 0;
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop_hook(data.mlx, listener, &data);
	mlx_hook(data.win, 17, 0, quit, &data);
	mlx_loop(data.mlx);
	return (0);
}
