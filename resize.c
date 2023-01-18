/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 07:55:30 by olahrizi          #+#    #+#             */
/*   Updated: 2023/01/18 11:02:55 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	resize(t_data *data)
{
	int		img_width;
	int		img_height;
	int		bits;
	int		size_line;
	int		endian;
	char		*img_data;
	int		x;
	int		y;
	int screen_width;
	int screen_height;

	screen_width = data->width;
	screen_height =  data->height;
	img_height = data->bg_height;
	img_width = data->bg_width;
	
	int bits2, size_line2, endian2;
	char *image_data;
	img_data = mlx_get_data_addr(data->background, &bits, &size_line, &endian);
	image_data = mlx_get_data_addr(data->image, &bits2, &size_line2, &endian2);

	char *dst;
	unsigned int color;
	
	for (y = 0; y < screen_height; y++)
	{
		for(x = 0; x < screen_width; x++)
		{
			dst = img_data +  ( ( (y * img_height) / screen_height) ) * size_line + ( (x * img_width) / screen_width) * (bits / 8);
			color = *((unsigned int *) dst);
			unsigned int *dest = (unsigned int *)image_data + data->width * y + x; //y * data->width + x;
			*dest = color;
		}
	}
}