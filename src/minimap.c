/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:52:41 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/05 10:54:15 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// if (x == (int)data->cast.pov.x && y == (int)data->cast.pov.y)
				// 	draw_square(data, coords, RED, 0);

void	init_minimap(t_data *data)
{
	data->mmap.scale = 8;
	data->mmap.view_radius = 9;
	data->mmap.view_size = (2 * data->mmap.view_radius) + 1;
	data->mmap.center.x = (data->mmap.scale * data->mmap.view_radius)
		+ data->mmap.scale + MAP_BG_BORDER;
	data->mmap.center.y = (data->mmap.scale * data->mmap.view_radius)
		+ data->mmap.scale + MAP_BG_BORDER;
	init_minimap_textures(data);
}

void	init_minimap_textures(t_data *data)
{
	data->mmap.cursor.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			"textures/cursor_3px.xpm", &data->mmap.cursor_tex_size,
			&data->mmap.cursor_tex_size);
	data->mmap.map_bg.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			"textures/map_bg.xpm", &data->mmap.map_bg_tex_size,
			&data->mmap.map_bg_tex_size);
	if (!data->mmap.cursor.img_ptr || !data->mmap.map_bg.img_ptr)
		ft_free_mlx(data);
	data->mmap.cursor.pix_addr = mlx_get_data_addr(data->mmap.cursor.img_ptr,
			&data->mmap.cursor.bpp, &data->mmap.cursor.line_len,
			&data->mmap.cursor.endian);
	data->mmap.map_bg.pix_addr = mlx_get_data_addr(data->mmap.map_bg.img_ptr,
			&data->mmap.map_bg.bpp, &data->mmap.map_bg.line_len,
			&data->mmap.map_bg.endian);
	if (!data->mmap.cursor.pix_addr || !data->mmap.map_bg.pix_addr)
		ft_free_mlx(data);
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;
	int	coords[2];

	update_minimap_render(data);
	y = data->mmap.start.y - 1;
	draw_map_bg(data, -1, -1);
	while (++y < data->mmap.end.y)
	{
		x = data->mmap.start.x - 1;
		while (++x < data->mmap.end.x)
		{
			if (x >= 0 && y >= 0 && y < data->map->max_y)
			{
				coords[0] = x;
				coords[1] = y;
				if (x < data->map->max_x[y] && data->map->map[y][x] == '0')
					draw_square(data, coords, WHITE, 1);
				else if (x < data->map->max_x[y] && data->map->map[y][x] == '1')
					draw_square(data, coords, BLACK, 1);
			}
		}
	}
	draw_player_cursor(data, data->mmap.center.x, data->mmap.center.y,
		data->mmap.cursor_tex_size);
}

void	draw_map_bg(t_data *data, int x, int y) //26 lines
{
	int				orig_x;
	unsigned int	color;

	orig_x = x;
	while (++y < data->mmap.map_bg_tex_size)
	{
		x = orig_x;
		while (++x < data->mmap.map_bg_tex_size)
		{
			color = (*(unsigned int *)((data->mmap.map_bg.pix_addr
							+ y * data->mmap.map_bg.line_len)
						+ (x * (data->mmap.cursor.bpp / 8))));
			if (color != INVIS)
				ft_draw_pixel(data, x + MAP_BG_BORDER,
					y + MAP_BG_BORDER, color);
		}
	}
}

void	draw_player_cursor(t_data *data, int x, int y, int size)
{
	data->mmap.angle = atan2(data->cast.dir.y, data->cast.dir.x);
	data->mmap.cx = size / 2;
	data->mmap.cy = size / 2;
	data->mmap.offset = (data->mmap.scale / 2) - (size / 2);
	data->mmap.i = -1;
	while (++data->mmap.i < size)
	{
		data->mmap.j = -1;
		while (++data->mmap.j < size)
		{
			data->mmap.rel_x = data->mmap.j - data->mmap.cx;
			data->mmap.rel_y = data->mmap.i - data->mmap.cy;
			data->mmap.src_x = (int)(cos(-data->mmap.angle) * \
data->mmap.rel_x - sin(-data->mmap.angle) * \
data->mmap.rel_y + data->mmap.cx);
			data->mmap.src_y = (int)(sin(-data->mmap.angle) * \
data->mmap.rel_x + cos(-data->mmap.angle) * \
data->mmap.rel_y + data->mmap.cy);
			draw_player_cursor_iter(data, x, y, size);
		}
	}
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
