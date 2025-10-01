/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:52:41 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/01 17:24:48 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_minimap(t_data *data, int map[][10])
{
	int mmap_x;
	int mmap_y;
	int mmap_size;

	mmap_x = WIDTH - 40;
	mmap_y = HEIGHT - 40;
	mmap_size = 30;
	
	draw_map(data, map, mmap_x, mmap_y, mmap_size);
	draw_player_pos(data, mmap_x - (mmap_size / 2), mmap_y - (mmap_size / 2), 10);
}

void	draw_map(t_data *data, int map[][10], int mmap_x, int mmap_y, int mmap_size)
{
	int end_x;
	int end_y;

	end_x = mmap_x + mmap_size;
	while(mmap_x < end_x)
	{
		end_y = mmap_y + mmap_size;
		while(mmap_y < end_y)
		{
			//ADD MAP (by step perhaps)
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