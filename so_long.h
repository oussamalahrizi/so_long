/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:42:57 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/18 11:02:27 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
#include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
#include <math.h>

// error messages
# define F_MAP "wrong map.\n"
# define EMPTY "empty map or contains newlines.\n"
# define INVALID_PATH_C "invalid path for collectibles.\n"
# define INVALID_PATH_E "invalid path for exit.\n"
# define INVALID_ARGS "invalid args for so_long.\n"
# define INVALID_EXT "invalid map extension.\n"
# define OPEN_FAILED "Failed to open the map file (probably doesn't exist).\n"
# define RES_FAILED "Failed to image ressource.\n"

# define NUM_ENEMIES 5

typedef struct s_var
{
	void		*win;
	void		*mlx;
}				t_var;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_enemy_can
{
	void		*enemy;
	float		x;
	float		y;
	int			map_x;
	int			map_y;
}				t_enemy_can;

typedef struct s_data
{
	void		*win;
	void		*mlx;
	t_pos		pos_player;
	int			player_x;
	int			player_y;
	int			num_enemies;
	t_enemy_can	*enemies;
	int			width;
	int			height;
	void		*wall;
	void		*collectible;
	void		*background;
	void		*image;
	int			bg_width;
	int			bg_height;
	void		*player;
	void		*player_left;
	void		*player_right;
	void		*enemy_right;
	void		*enemy_left;
	void		*door;
	char		*map_path;
	char		**map;
	char		**holder;
	int			moves;
	int			map_count;
	int			direction;
	int			speed;
}				t_data;

void			init_stuff(t_data *data, int bonus);
char			*str_join(char *s1, char *s2);
char			**ft_split(char *s, char c);
void			*ft_calloc(size_t nelem, size_t elsize);
char			*ft_substr(char *s, unsigned int start, size_t len);
void			set_map(t_data *data);
void			flood_fill(t_data *data, t_pos pos, char c, char imposter);
void			check_map(t_data *data);
void			go_up(t_data *data, int c);
void			go_left(t_data *data, int c);
void			go_down(t_data *data, int c);
void			go_right(t_data *data, int c);
int				count_collect_exit(char **holder, char c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			set_map(t_data *data);
void			init_map(t_data *data);
void			resize(t_data *data);
void			spawn_enemies(t_data *data);

#endif