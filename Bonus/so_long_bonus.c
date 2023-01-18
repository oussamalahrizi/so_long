/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:45:42 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/18 15:30:35 by olahrizi         ###   ########.fr       */
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
	if (e == 13)
		go_up(data, collectible_count);
	else if (e == 0)
		go_left(data, collectible_count);
	else if (e == 1)
		go_down(data, collectible_count);
	else if (e == 2)
		go_right(data, collectible_count);
	else if (e == 53)
		quit(data);
	return (0);
}

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
	// setting enemies
	// if (data->enemies[0].pos.x > target_x)
	// {
	// 	data->enemies[0].enemy = data->enemy_left;
	// 	data->enemies[0].pos.x += -data->speed;
	// }
	// else if (data->enemies[0].pos.x < target_x)
	// {
	// 	data->enemies[0].enemy = data->enemy_right;
	// 	data->enemies[0].pos.x += data->speed;
	// }
	// if (data->enemies[0].pos.y > target_y)
	// 	data->enemies[0].pos.y += -data->speed;
	// else if (data->enemies[0].pos.y < target_y)
	// 	data->enemies[0].pos.y += data->speed;
	mlx_clear_window(data->mlx, data->win);
	set_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_x,
		data->player_y);
	printf("enemy : %d %d\n", data->enemies[0].pos.x, data->enemies[0].pos.y);
	// mlx_put_image_to_window(data->mlx, data->win, data->enemies[0].enemy, data->enemies[0].pos.x, data->enemies[0].pos.y);
	printf("player : %d %d\n", data->player_x, data->player_y);
	while (1);
}

void move_enemy(t_data *data)
{
	int	target_x;
	int	target_y;

	target_x = data->pos_player.x * 50;
	target_y = data->pos_player.y * 50;
	// printf("enemy_0_x : %d enemy_0_y : %d\n", data->enemies[0].pos.x, data->enemies[0].pos.y);
	
	mlx_clear_window(data->mlx, data->win);
	set_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->enemies[0].enemy, data->enemies[0].pos.x, data->enemies[0].pos.y);
	printf("enemy : %d %d\n", data->enemies[0].pos.x, data->enemies[0].pos.y);
}


int listener(t_data *data)
{
	move_player(data);
	// move_enemy(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

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
	init_stuff(&data);
	init_map(&data);
	set_map(&data);
	check_map(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop_hook(data.mlx, listener, &data);
	mlx_hook(data.win, 17, 0, quit, &data);
	mlx_loop(data.mlx);
	return (0);
}
