/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:57:47 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/23 10:58:06 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square(t_data *data, int coords[2], unsigned int color, int alpha)
{
	int	i;
	int	j;
	int	win_x;
	int	win_y;

	win_x = data->mmap.center.x + ((coords[0] - (int)data->cast.pov.x)
			* data->mmap.scale);
	win_y = data->mmap.center.y + ((coords[1] - (int)data->cast.pov.y)
			* data->mmap.scale);
	i = 0;
	while (i < data->mmap.scale)
	{
		j = 0;
		while (j < data->mmap.scale)
		{
			if (alpha == 0)
				ft_draw_pixel(data, j + win_x, i + win_y, color);
			else
				ft_draw_pixel(data, j + win_x, i + win_y,
					get_alpha_color (data, j + win_x, i + win_y, color));
			j++;
		}
		i++;
	}
}

unsigned int	get_alpha_color(t_data *data, int target_x, int target_y,
	unsigned int new_color)
{
	unsigned int	target_color;
	unsigned int	color_mix;

	target_color = (*(unsigned int *)((data->img.pix_addr + target_y
					* data->img.line_len) + (target_x * (data->img.bpp / 8))));
	color_mix = (
			(((target_color >> 16 & 0xFF) + (new_color >> 16 & 0xFF)) / 2) << 16
			| (((target_color >> 8 & 0xFF) + (new_color >> 8 & 0xFF)) / 2) << 8
			| (((target_color & 0xFF) + (new_color & 0xFF)) / 2));
	return (color_mix);
}

void	update_minimap_render(t_data *data)
{
	data->mmap.start.x = (int)data->cast.pov.x - data->mmap.view_radius;
	data->mmap.start.y = (int)data->cast.pov.y - data->mmap.view_radius;
	data->mmap.end.x = (int)data->cast.pov.x + data->mmap.view_radius;
	data->mmap.end.y = (int)data->cast.pov.y + data->mmap.view_radius;
}
