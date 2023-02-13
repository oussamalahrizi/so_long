/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:38:20 by olahrizi          #+#    #+#             */
/*   Updated: 2023/02/13 13:01:04 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



char	**read_map(t_data *data)
{
	int		fd;
	char	*file;
	char	*buff;
	char	**map;
	int		readed;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
	{
		write(2, OPEN_FAILED, ft_strlen(OPEN_FAILED));
		exit(1);
	}
	readed = 1;
	buff = malloc(sizeof(char) * 11);
	file = (char *)ft_calloc(1, 1);
	while (readed)
	{
		readed = read(fd, buff, 10);
		if (readed < 0)
		{
			free(buff);
			free(file);
			return (NULL);
		}
		buff[readed] = 0;
		file = str_join(file, buff);
	}
	if (!*file || !check_new_lines(file))
	{
		free(buff);
		free(file);
		return (NULL);
	}
	map = ft_split(file, '\n');
	data->holder = ft_split(file, '\n');
	free(buff);
	free(file);
	return (map);
}

int	map_lines(char **map)
{
	int	c;

	c = 0;
	while (*map)
	{
		c++;
		map++;
	}
	return (c);
}

// todo : rectangle , surrounded by 1s, contains only 1s, 0s, Cs and one P;



// checking imposters


// checking map contains at least a C , one P and one E
int	check_collectible(char **map)
{
	int	i;
	int	c;
	int	j;

	c = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				c++;
			i++;
		}
		j++;
	}
	if (!c)
	{
		ft_printf("collectible\n");
		return (0);
	}
	return (1);
}

int	check_player_exit(char **map, t_data *data)
{
	int	i;
	int	p;
	int	e;
	int	j;

	p = 0;
	e = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				data->pos_player.x = i;
				data->pos_player.y = j;
				p++;
			}
			else if (map[j][i] == 'E')
				e++;
			i++;
		}
		j++;
	}
	if (!p || p > 1 || !e || e > 1)
	{
		ft_printf("player or exit\n");
		return (0);
	}
	return (1);
}


void	init_stuff(t_data *data, int bonus)
{
	data->map = read_map(data);
	if (!data->map)
	{
		write(2, EMPTY, ft_strlen(EMPTY));
		exit(1);
	}
	if (!check_rectangle(data->map) || !check_extern_walls(data->map)
		|| !check_imposter(data->map) || !check_collectible(data->map)
		|| !check_player_exit(data->map, data))
	{
		write(2, F_MAP, ft_strlen(F_MAP));
		exit(1);
	}
	data->map_count = map_lines(data->map);
	data->mlx = mlx_init();
	data->width = ft_strlen(*(data->map)) * 50;
	data->height = data->map_count * 50;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "so_long");
	data->moves = 0;
	data->player_x = data->pos_player.x * 50;
	data->player_y = data->pos_player.y * 50;
	data->speed = 5;
	data->direction = 1;
	if (bonus)
		spawn_enemies(data);
}

void import_res(t_data *data)
{
	int x;
	int y;
	data->wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &x, &y);
	data->background = mlx_xpm_file_to_image(data->mlx, "./textures/bg.xpm", &data->bg_width, &data->bg_height);
	data->player_left = mlx_xpm_file_to_image(data->mlx, "./textures/padoru-left.xpm", &x,
			&y);
	data->player_right = mlx_xpm_file_to_image(data->mlx, "./textures/padoru-right.xpm", &x,
			&y);
	data->door = mlx_xpm_file_to_image(data->mlx, "./textures/door.xpm", &x, &y);
	data->collectible = mlx_xpm_file_to_image(data->mlx, "./textures/candy.xpm",
			&x, &y);
	
	data->image = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->wall || !data->player_left || !data->player_right
		|| !data->door || !data->collectible || !data->background || !data->image)
	{
		perror("error ");
		exit(1);
	}
	data->player = data->player_right;
}

void init_map(t_data *data)
{
	(import_res(data), resize(data));
}
void	set_map(t_data *data)
{
	int x;
	int y;
	
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
			// else if (data->map[y][x] == 'X')
			// 	mlx_put_image_to_window(data->mlx, data->win, data->enemy_right, x
			// 			* 50, y * 50);
			x++;
		}
		y++;
	}
}