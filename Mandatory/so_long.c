/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:45:42 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/18 11:25:52 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int quit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("you exited the game.\n");
	exit(1);
	return (0);
}

int key_hook(int e, t_data *data) //original prototype int key_hook(int event, void *data, int mask, void *win)
{	
	if (e == 13)
		go_up(data, count_collect_exit(data->map, 'C'));
	else if (e == 0)
		go_left(data, count_collect_exit(data->map, 'C'));
	else if (e == 1)
		go_down(data, count_collect_exit(data->map, 'C'));
	else if (e == 2)
		go_right(data, count_collect_exit(data->map, 'C'));
	else if (e == 53)
		quit(data);
	return (0);
}


int move_player(t_data *data)
{
	int target_x = data->pos_player.x * 50;
	int target_y = data->pos_player.y * 50;
	
	if (data->player_x > target_x)
		data->player = data->player_left;
	else if (data->player_x < target_x)
		data->player = data->player_right;
	data->player_x = target_x;
	data->player_y = target_y;
	// if (data->player_y > target_y)
	// 	data->player_y += -data->speed;
	// else if (data->player_y < target_y)
	// 	data->player_y += data->speed;
	mlx_clear_window(data->mlx, data->win);
	set_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->player, data->player_x, data->player_y);
	return (0);
}



int	main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
	{
		write(2, INVALID_ARGS, ft_strlen(INVALID_ARGS));
		exit(1);
	}
	if(ft_strncmp(".ber", av[1] + ft_strlen(av[1]) - 4, 4))
	{
		write(2, INVALID_EXT, ft_strlen(INVALID_EXT));
		exit(1);
	}
	data.map_path = av[1];
	init_stuff(&data);
	init_map(&data);
	set_map(&data);
	check_map(&data);
	mlx_hook(data.win, 2, 0,  key_hook, &data);
	mlx_loop_hook(data.mlx, move_player, &data);
	mlx_hook(data.win, 17, 0, quit, &data);
	// system("leaks a.out");
	mlx_loop(data.mlx);
	return (0);
}
