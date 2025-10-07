/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:52:41 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/07 14:13:14 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_minimap(t_data *data)
{
	data->mmap.scale = 10;
	data->mmap.x0 = data->mmap.scale;
	data->mmap.y0 = data->mmap.scale;
	data->mmap.height = 10; // needs to be dynamic
	data->mmap.length = 10;
	data->mmap.facing_x = 0;
	data->mmap.facing_y = 0;
	data->mmap.view_rad = 5;
	data->mmap.view_size = (2 * data->mmap.view_rad) + 1;
}

void	draw_minimap(t_data *data, int map[][19])
{
	int x;
	int y;

	y = 0;
	while(y < data->mmap.height)
	{
		x = 0;
		while(x < 19)//map[y][x])
		{
			if (map[y][x] == 0)
				draw_square(data, x, y, WHITE, 1);
			else if (map[y][x] == 1)
				draw_square(data, x, y, BLACK, 1);
			else 
				draw_square(data, x, y, GRAY, 1);
			if (x == (int)data->cast.pov_x && y == (int)data->cast.pov_y)
			{
				draw_square(data, x, y, GREEN, 0);
				if ((x % data->mmap.scale == data->mmap.scale / 2) && (y % data->mmap.scale == data->mmap.scale / 2))
					draw_player_dir(data, x, y);
			}
			x++;
		}	
		y++;
	}
}

void	draw_square(t_data *data, int x, int y, unsigned int color, int alpha)
{
	int i;
	int j;
	
	i = 0;
	while (i < data->mmap.scale)
	{
		j = 0;
		while (j < data->mmap.scale)
		{
			if (alpha == 0)
				ft_draw_pixel(data, j + ((x * data->mmap.scale) + data->mmap.x0),
					i + ((y * data->mmap.scale) + data->mmap.y0), color);
			else
				ft_draw_pixel(data, j + ((x * data->mmap.scale) + data->mmap.x0),
					i + ((y * data->mmap.scale) + data->mmap.y0), get_alpha_color
					(data, j + ((x * data->mmap.scale) + data->mmap.x0), 
					i + ((y * data->mmap.scale) + data->mmap.y0), color));
			j++;
		}
		i++;
	}
}

void	draw_player_dir(t_data *data, int x0, int y0)
{
	int height = 3;
	int base = 6;
    int half_base = base / 2;
	int x_start;
	int x_end;
	int y;

	
	y0 -= data->mmap.scale / 2; //changes with direction
	y = -1;
	while (++y < 10)
    {
        x_start = (x0 - (half_base * (height - y)) / height) - 1;
        x_end   = x0 + (half_base * (height - y)) / height;
        for (int x = x_start; x <= x_end; x++)
        {
			ft_draw_pixel(data, x, y0 - y, GREEN);
        }
    }
}

unsigned int get_alpha_color(t_data *data, int target_x, int target_y,
	unsigned int new_color)
{
	unsigned int target_color;
	unsigned int color_mix;
	
	target_color = (*(int *)((data->img.pix_addr + target_y * data->img.line_len) + (target_x * (data->img.bpp / 8))));
	color_mix = (
    (((target_color >> 16 & 0xFF) + (new_color >> 16 & 0xFF)) / 2) << 16 |
    (((target_color >> 8  & 0xFF) + (new_color >> 8  & 0xFF)) / 2) << 8  |
    (((target_color       & 0xFF) + (new_color       & 0xFF)) / 2));

	return (color_mix);
}
