/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 04:01:26 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/18 13:48:14 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(t_data *data)
{
	data->moves++;
	ft_printf("Total moves : %d\n", data->moves);
}

void	go_up(t_data *data, int collectible)
{
	if (data->map[data->pos_player.y - 1][data->pos_player.x] == 'X')
	{
		print_move(data);
		printf("you lost\n");
		exit (1);
	}
	else if (data->map[data->pos_player.y - 1][data->pos_player.x] != '1'
		&& data->map[data->pos_player.y - 1][data->pos_player.x] != 'E')
	{
		print_move(data);
		data->pos_player.y -= 1;
		data->map[data->pos_player.y][data->pos_player.x] = 'P';
		data->map[data->pos_player.y + 1][data->pos_player.x] = '0';
	}
	else if (data->map[data->pos_player.y - 1][data->pos_player.x] != '1')
	{
		if (!collectible && data->map[data->pos_player.y
				- 1][data->pos_player.x] == 'E')
		{
			print_move(data);
			ft_printf("Congrats you win!\n");
			exit(0);
		}
		else if (data->map[data->pos_player.y - 1][data->pos_player.x] != 'E')
		{
			print_move(data);
			data->pos_player.y -= 1;
			data->map[data->pos_player.y][data->pos_player.x] = 'P';
			data->map[data->pos_player.y + 1][data->pos_player.x] = '0';
		}
	}
}

void	go_left(t_data *data, int collectible)
{
	if (data->map[data->pos_player.y][data->pos_player.x - 1] == 'X')
	{
		print_move(data);
		printf("you lost\n");
		exit (1);
	}
	else if (data->map[data->pos_player.y][data->pos_player.x - 1] != '1'
		&& data->map[data->pos_player.y][data->pos_player.x - 1] != 'E')
	{
		print_move(data);
		data->pos_player.x -= 1;
		data->map[data->pos_player.y][data->pos_player.x] = 'P';
		data->map[data->pos_player.y][data->pos_player.x + 1] = '0';
	}
	else if (data->map[data->pos_player.y][data->pos_player.x - 1] != '1')
	{
		if (!collectible && data->map[data->pos_player.y][data->pos_player.x
			- 1] == 'E')
		{
			print_move(data);
			ft_printf("Congrats you win!\n");
			exit(0);
		}
		else if (data->map[data->pos_player.y][data->pos_player.x - 1] != 'E')
		{
			print_move(data);
			data->pos_player.x -= 1;
			data->map[data->pos_player.y][data->pos_player.x] = 'P';
			data->map[data->pos_player.y][data->pos_player.x + 1] = '0';
		}
	}
}

void	go_down(t_data *data, int collectible)
{
	if (data->map[data->pos_player.y + 1][data->pos_player.x] == 'X')
	{
		print_move(data);
		printf("you lost\n");
		exit (1);
	}
	else if (data->map[data->pos_player.y + 1][data->pos_player.x] != '1'
		&& data->map[data->pos_player.y + 1][data->pos_player.x] != 'E')
	{
		data->pos_player.y += 1;
		print_move(data);
		data->map[data->pos_player.y][data->pos_player.x] = 'P';
		data->map[data->pos_player.y - 1][data->pos_player.x] = '0';
	}
	else if (data->map[data->pos_player.y + 1][data->pos_player.x] != '1')
	{
		if (!collectible && data->map[data->pos_player.y
				+ 1][data->pos_player.x] == 'E')
		{
			print_move(data);
			ft_printf("Congrats you win!\n");
			exit(0);
		}
		else if (data->map[data->pos_player.y + 1][data->pos_player.x] != 'E')
		{
			print_move(data);
			data->pos_player.y += 1;
			data->map[data->pos_player.y][data->pos_player.x] = 'P';
			data->map[data->pos_player.y - 1][data->pos_player.x] = '0';
		}
	}
}

void	go_right(t_data *data, int collectible)
{
	if (data->map[data->pos_player.y][data->pos_player.x + 1] == 'X')
	{
		print_move(data);
		printf("you lost\n");
		exit (1);
	}
	else if (data->map[data->pos_player.y][data->pos_player.x + 1] != '1'
		&& data->map[data->pos_player.y][data->pos_player.x + 1] != 'E')
	{
		print_move(data);
		data->pos_player.x += 1;
		data->map[data->pos_player.y][data->pos_player.x] = 'P';
		data->map[data->pos_player.y][data->pos_player.x - 1] = '0';
	}
	else if (data->map[data->pos_player.y][data->pos_player.x + 1] != '1')
	{
		if (!collectible && data->map[data->pos_player.y][data->pos_player.x
			+ 1] == 'E')
		{
			print_move(data);
			ft_printf("Congrats you win!\n");
			exit(0);
		}
		else if (data->map[data->pos_player.y][data->pos_player.x + 1] != 'E')
		{
			print_move(data);
			data->pos_player.x += 1;
			data->map[data->pos_player.y][data->pos_player.x] = 'P';
			data->map[data->pos_player.y][data->pos_player.x - 1] = '0';
		}
	}
}
