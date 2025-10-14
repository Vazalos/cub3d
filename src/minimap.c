/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:52:41 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/14 16:37:23 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_minimap(t_data *data)
{
	data->mmap.scale = 10;
	data->mmap.view_radius = 7;
	data->mmap.view_size = (2 * data->mmap.view_radius) + 1;
	data->mmap.center_x = (data->mmap.scale * data->mmap.view_radius) + data->mmap.scale;
	data->mmap.center_y = (data->mmap.scale * data->mmap.view_radius) + data->mmap.scale;
	data->mmap.start_x = (int)data->cast.pov_x - data->mmap.view_radius;
	data->mmap.start_y = (int)data->cast.pov_y - data->mmap.view_radius;
	data->mmap.end_x = (int)data->cast.pov_x + data->mmap.view_radius;
	data->mmap.end_y = (int)data->cast.pov_y + data->mmap.view_radius;
	data->mmap.facing_x = 0;
	data->mmap.facing_y = 0;
}

void	draw_minimap(t_data *data)
{
	int x;
	int y;

	data->mmap.start_x = (int)data->cast.pov_x - data->mmap.view_radius;
	data->mmap.start_y = (int)data->cast.pov_y - data->mmap.view_radius;
	data->mmap.end_x = (int)data->cast.pov_x + data->mmap.view_radius;
	data->mmap.end_y = (int)data->cast.pov_y + data->mmap.view_radius;

	y = data->mmap.start_y;
	while(y < data->mmap.end_y)
	{
		x = data->mmap.start_x;
		while(x < data->mmap.end_x) 
		{
			if (x >= 0 && y >= 0 && (int)x <= data->map->max_x[y]
				&& (int)y < data->map->max_y && data->map->map[(int)y][(int)x] == '0')
				draw_square(data, x, y, WHITE, 1);
			else if (x >= 0 && y >= 0 && (int)x <= data->map->max_x[(int)y]
				&& (int)y < data->map->max_y && data->map->map[(int)y][(int)x] == '1')
				draw_square(data, x, y, BLACK, 1);
			else 
				draw_square(data, x, y, GRAY, 1);
			if ((int)x == (int)data->cast.pov_x && (int)y == (int)data->cast.pov_y)
			{
				draw_square(data, x, y, GREEN, 0);
				//if ((x % data->mmap.scale == data->mmap.scale / 2) && (y % data->mmap.scale == data->mmap.scale / 2))
				//	draw_player_dir(data, x, y);
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
	int offset_x;
	int offset_y;
	int	win_x;
	int win_y;

	offset_x = x - (int)data->cast.pov_x;
	offset_y = y - (int)data->cast.pov_y;
	win_x = data->mmap.center_x + (offset_x * data->mmap.scale);
	win_y = data->mmap.center_y + (offset_y * data->mmap.scale);
	
	i = 0;
	while (i < data->mmap.scale)
	{
		j = 0;
		while (j < data->mmap.scale)
		{
			if (alpha == 0)
				ft_draw_pixel(data, j + (int)win_x,
					i + (int)win_y, color);
			else
				ft_draw_pixel(data, j + (int)win_x,
					i + (int)win_y, get_alpha_color
					(data, j + win_x, 
					i + win_y, color));
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
