/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:52:41 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/06 17:17:08 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int get_semi_alpha_color(t_data *data, int target_x, int target_y,
	unsigned int new_color);

void	ft_draw_minimap(t_data *data, int map[][10])
{
	draw_map(data, map, data->mmap.x0, data->mmap.y0);
}

void init_minimap(t_data *data)
{
	data->mmap.x0 = 0;
	data->mmap.y0 = 0;
	data->mmap.scale = 10;
	data->mmap.height = 10; // needs to be dynamic
	data->mmap.length = 10;
	data->mmap.facing_x = 0;
	data->mmap.facing_y = 0;
}


void	draw_map(t_data *data, int map[][10], int x0, int y0)
{
	int x;
	int y;
	int map_size;

	map_size = 10; // has to be made dynamic
	y = 0;
	while(y < data->mmap.height * data->mmap.scale)
	{
		x = 0;
		while(x < data->mmap.height * data->mmap.scale) //JUST DO A 'GET LINE LEN' for MAP X
		{
			if ((x / data->mmap.scale) == (int)data->cast.pov_x && (y / data->mmap.scale) == (int)data->cast.pov_y)
			{
				ft_draw_pixel(data, x + x0, y + y0, GREEN);
				//ft_draw_pixel(data, x + x0, y + y0, get_semi_alpha_color(data, x, y, WHITE));
				if ((x % data->mmap.scale == data->mmap.scale / 2) && (y % data->mmap.scale == data->mmap.scale / 2))
					draw_player_dir(data, x, y);
			}
			else if (map[x / data->mmap.scale][y / data->mmap.scale] == 0)
				ft_draw_pixel(data, x + x0, y + y0, get_semi_alpha_color(data, x, y, WHITE));
			else if (map[x / data->mmap.scale][y / data->mmap.scale] == 1)
				ft_draw_pixel(data, x + x0, y + y0, get_semi_alpha_color(data, x, y, BLACK));
			x++;
		}	
		y++;
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

unsigned int get_semi_alpha_color(t_data *data, int target_x, int target_y,
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
