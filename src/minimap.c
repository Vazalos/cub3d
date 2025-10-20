/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:52:41 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/20 17:13:00 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_minimap(t_data *data)
{
	data->mmap.scale = 8;
	data->mmap.view_radius = 9;
	data->mmap.view_size = (2 * data->mmap.view_radius) + 1;
	data->mmap.center_x = (data->mmap.scale * data->mmap.view_radius)
		+ data->mmap.scale + MAP_BG_BORDER;
	data->mmap.center_y = (data->mmap.scale * data->mmap.view_radius)
		+ data->mmap.scale + MAP_BG_BORDER;
	data->mmap.cursor.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			"textures/cursor_3px.xpm", &data->mmap.cursor_tex_size,
			&data->mmap.cursor_tex_size);
	data->mmap.map_bg.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			"textures/map_bg.xpm", &data->mmap.map_bg_tex_size,
			&data->mmap.map_bg_tex_size);
	if (!data->mmap.cursor.img_ptr || !data->mmap.map_bg.img_ptr)
	{
		ft_free_bonus_textures(data);
		ft_free_mlx(data);
	}
	data->mmap.cursor.pix_addr = mlx_get_data_addr(data->mmap.cursor.img_ptr,
			&data->mmap.cursor.bpp, &data->mmap.cursor.line_len,
			&data->mmap.cursor.endian);
	data->mmap.map_bg.pix_addr = mlx_get_data_addr(data->mmap.map_bg.img_ptr,
			&data->mmap.map_bg.bpp, &data->mmap.map_bg.line_len,
			&data->mmap.map_bg.endian);
}

/*
void	draw_player_cursor(t_data *data, int x, int y, int size)
{
	int i;
	int j;
	unsigned int color;
	int offset;

	offset = (data->mmap.scale / 2) - (data->mmap.cursor_tex_size / 2);
	i = 0;
	while (i < size) //y
	{
		j = 0;
		while (j < size) //x
		{
			color = (*(unsigned int *)((data->mmap.cursor.pix_addr + i * 
			data->mmap.cursor.line_len) + (j * (data->mmap.cursor.bpp / 8))));
			if (color != INVIS)
				ft_draw_pixel(data, x + offset + j, y + offset + i, color);
			j++;
		}
		i++;
	}
}*/

void	draw_player_cursor(t_data *data, int x, int y, int size)
{
	int i, j, cx, cy;
	int src_x, src_y;
	unsigned int color;
	int offset;
	double angle = atan2(data->cast.dir_y, data->cast.dir_x);

	cx = size / 2; // center of image
	cy = size / 2;
	offset = (data->mmap.scale / 2) - (size / 2);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			int rel_x = j - cx;
			int rel_y = i - cy;
			src_x = (int)(cos(-angle) * rel_x - sin(-angle) * rel_y + cx);
			src_y = (int)(sin(-angle) * rel_x + cos(-angle) * rel_y + cy);
			if (src_x >= 0 && src_x < size && src_y >= 0 && src_y < size)
			{
				color = (*(unsigned int *)((data->mmap.cursor.pix_addr + src_y * data->mmap.cursor.line_len) + (src_x * (data->mmap.cursor.bpp / 8))));
				if (color != INVIS)
					ft_draw_pixel(data, x + offset + j, y + offset + i, color);
			}
		}
	}
}

void	draw_map_bg(t_data *data, int x, int y, int sq) //26 lines
{
	int				orig_x;
	unsigned int	color;
	int				i;
	int				j;

	orig_x = x;
	while (++y < data->mmap.map_bg_tex_size)
	{
		x = orig_x;
		while (++x < data->mmap.map_bg_tex_size)
		{
			color = (*(unsigned int *)((data->mmap.map_bg.pix_addr + y *
				data->mmap.map_bg.line_len) + (x * (data->mmap.cursor.bpp / 8))));
			if (color != INVIS)
			{
				i = -1;
				while (++i < sq)
				{
					j = -1;
					while (++j < sq)
						ft_draw_pixel(data, (x * sq) + i + MAP_BG_BORDER,
							(y * sq) + j + MAP_BG_BORDER, color);
				}			
			}
		}
	}
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;

	update_minimap_render(data);
	y = data->mmap.start_y - 1;
	draw_map_bg(data, -1, -1, 1);
	while (++y < data->mmap.end_y)
	{
		x = data->mmap.start_x - 1;
		while (++x < data->mmap.end_x)
		{
			if (x >= 0 && y >= 0 && x < data->map->max_x[y]
				&& y < data->map->max_y && data->map->map[y][x] == '0')
				draw_square(data, x, y, WHITE, 1);
			else if (x >= 0 && y >= 0 && x < data->map->max_x[y]
				&& y < data->map->max_y && data->map->map[y][x] == '1')
				draw_square(data, x, y, BLACK, 1);
		}
	}
	draw_player_cursor(data, data->mmap.center_x, data->mmap.center_x,
		data->mmap.cursor_tex_size);
}

void	draw_square(t_data *data, int x, int y, unsigned int color, int alpha)
{
	int	i;
	int	j;
	int	offset_x;
	int	offset_y;
	int	win_x;
	int	win_y;

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
				ft_draw_pixel(data, j + win_x,
					i + win_y, color);
			else
				ft_draw_pixel(data, j + win_x,
					i + win_y, get_alpha_color
					(data, j + win_x, 
					i + win_y, color));
			j++;
		}
		i++;
	}
}
