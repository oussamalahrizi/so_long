/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:08:16 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/25 21:35:22 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spawn_enemies(t_data *data)
{
	int num_enemies = NUM_ENEMIES;
	int i;
	int random_row;
	int random_col;
	int x;
	int y;

	i = 0;
	x = 0;
	while (num_enemies >= count_collect_exit(data->map, '0'))
		num_enemies--;
	data->enemies = malloc(sizeof(t_enemy_can) * num_enemies);
	data->enemy_right = mlx_xpm_file_to_image(data->mlx,
			"textures/enemy-right.xpm", &x, &y);
	data->enemy_left = mlx_xpm_file_to_image(data->mlx,
			"textures/enemy-left.xpm", &x, &y);
	if (!data->enemy_right || !data->enemy_left)
	{
		write(2, RES_FAILED, ft_strlen(RES_FAILED));
		exit(1);
	}
	data->num_enemies = num_enemies;
	
	while (i < num_enemies)
	{
		// int j = 5;
		random_col = rand() % data->map_count;
		random_row = rand() % ft_strlen(*(data->map));
		while (data->map[random_col][random_row] != '0')
		{
			random_col = rand() % data->map_count;
			random_row = rand() % ft_strlen(*(data->map));
		}
		// random_col = rand() % data->map_count;
		// random_row = rand() % ft_strlen(*(data->map));
		if (data->map[random_col][random_row] == '0')
		{
			// data->map[random_col][random_row] = 'X';
			data->enemies[i].enemy = data->enemy_right; // teswira dyal l'enemy
			data->enemies[i].x = random_row * 50;
			data->enemies[i].y = random_col * 50;
			data->enemies[i].map_x = random_row;
			data->enemies[i].map_y = random_col;
		}
		// else
		// 	i--;
		i++;
	}
}