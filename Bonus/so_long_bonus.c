/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:45:42 by olahrizi          #+#    #+#             */
/*   Updated: 2023/02/16 13:53:03 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

typedef struct s_function_helper
{
	int	player_x;
	int	player_y;
	int	target_x;
	int	target_y;
	int	dir;
}	t_f_helper;

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

void	move_enemy_helper(t_data *data, t_f_helper *vars, int i, int flag)
{
	int	x;
	int	y;

	if (flag)
	{
		x = vars->player_x;
		y = vars->target_x;
	}
	else
	{
		x = vars->player_y;
		y = vars->target_y;
	}
	if (x - y > 0)
		vars->dir = 1;
	else
		vars->dir = -1;
	if (valid_position(data, data->enemies[i].map_x,
			data->enemies[i].map_y + vars->dir))
		data->enemies[i].map_y += vars->dir;
}

void	move_enemy(t_data *data)
{
	t_f_helper	vars;
	int			i;

	vars.player_x = data->player_x;
	vars.player_y = data->player_y;
	i = -1;
	while (++i < data->num_enemies)
	{
		vars.target_x = data->enemies[i].x;
		vars.target_y = data->enemies[i].y;
		if (vars.target_x - data->enemies[i].map_x * 50
			|| vars.target_y - data->enemies[i].map_y * 50)
		{
			move_enemy_2(data->enemies[i].map_x * 50,
				data->enemies[i].map_y * 50, data, i);
			i++;
			continue ;
		}
		if (vars.target_x != vars.player_x)
			move_enemy_helper(data, &vars, i, 1);
		else if (vars.target_y != vars.player_y)
			move_enemy_helper(data, &vars, i, 0);
	}
}

int	listener(t_data *data)
{
	clock_t	t;
	clock_t	curr;

	t = clock();
	move_player(data);
	move_enemy(data);
	draw_enemy(data);
	curr = clock();
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
