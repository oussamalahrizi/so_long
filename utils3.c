/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:17:13 by Exiled            #+#    #+#             */
/*   Updated: 2023/02/15 20:17:13 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_data *data)
{
	(import_res(data), resize(data));
}

void	set_map(t_data *data)
{
	int	x;
	int	y;

	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall, x
					* 50, y * 50);
			else if (data->map[y][x] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win, data->collectible,
					x * 50, y * 50);
			}
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->door, x
					* 50, y * 50);
			x++;
		}
		y++;
	}
}
