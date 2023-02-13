/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Exiled <exiled@owly.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 07:55:30 by olahrizi          #+#    #+#             */
/*   Updated: 2023/02/13 12:37:19 by Exiled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_helper
{
	char			*img_data;
	char			*image_data;
	int				img_width;
	int				img_height;
	int				bits;
	int				size_line;
	int				endian;
	int				screen_width;
	int				screen_height;
	int				bits2;
	int				size_line2;
	int				endian2;
	unsigned int	color;
}	t_helper;

void	initialize(t_helper *helper, t_data *data)
{
	helper->screen_width = data->width;
	helper->screen_height = data->height;
	helper->img_height = data->bg_height;
	helper->img_width = data->bg_width;
	helper->img_data = mlx_get_data_addr(data->background, &helper->bits,
			&helper->size_line, &helper->endian);
	helper->image_data = mlx_get_data_addr(data->image, &helper->bits2,
			&helper->size_line2, &helper->endian2);
}

void	resize(t_data *data)
{
	t_helper		helper;
	char			*dst;
	int				y;
	int				x;
	unsigned int	*dest;

	y = 0;
	initialize(&helper, data);
	while (y < helper.screen_height)
	{
		x = 0;
		while (x < helper.screen_width)
		{
			dst = helper.img_data
				+ (((y * helper.img_height) / helper.screen_height))
				* helper.size_line + ((x * helper.img_width)
					/ helper.screen_width) * (helper.bits / 8);
			helper.color = *((unsigned int *)dst);
			dest = (unsigned int *)helper.image_data + data->width * y + x;
			*dest = helper.color;
			x++;
		}
		y++;
	}
}
