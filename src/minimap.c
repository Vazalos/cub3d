/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:52:41 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/03 17:12:18 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_minimap(t_data *data, int map[][10])
{
	int mmap_x0;
	int mmap_y0;
	int mmap_scale;

	mmap_x0 = 0;
	mmap_y0 = 0;
	mmap_scale = 10;
	
	draw_map(data, map, mmap_x0, mmap_y0, mmap_scale);
	//draw_player_pos(data, mmap_x - (mmap_size / 2), mmap_y - (mmap_size / 2), 10);
}

void	draw_map(t_data *data, int map[][10], int mmap_x0, int mmap_y0, int mmap_scale)
{
	int mmap_x;
	int mmap_y;
	int map_size;

	map_size = 10; // has to be made dynamic
	mmap_x = 0;
	while(mmap_x < map_size * mmap_scale)
	{
		mmap_y = 0;
		while(mmap_y < map_size * mmap_scale)
		{
			if ((mmap_x / mmap_scale) == (int)data->cast.pov_x && (mmap_y / mmap_scale) == (int)data->cast.pov_y)
				ft_draw_pixel(data, mmap_x + mmap_x0, mmap_y + mmap_y0, GREEN);
			else if (map[mmap_x / mmap_scale][mmap_y / mmap_scale] == 0)
				ft_draw_pixel(data, mmap_x + mmap_x0, mmap_y + mmap_y0, WHITE);
			else if (map[mmap_x / mmap_scale][mmap_y / mmap_scale] > 0)
				ft_draw_pixel(data, mmap_x + mmap_x0, mmap_y + mmap_y0, BLACK);
			mmap_y++;
		}	
		mmap_x++;
	}
}

void	draw_player_pos(t_data *data, int x0, int y0, int height)
{
	int base = 6;
    int half_base = base / 2;
	int x_start;
	int x_end;
	int y;
	
	y = -1;
	while (++y < 10)
    {
        x_start = x0 - (half_base * (height - y)) / height;
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
	
}