/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:06:15 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/01 14:47:23 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	wall_color(t_data *data, int x)
{
	if (data->cast.side == 1)
	{
		if (data->cast.ray_dir_y < 0) //N
			data->cast.wall_color = RED;
		else //S
			data->cast.wall_color = GREEN;
	}
	else if (data->cast.side == 0)
	{
		if (data->cast.ray_dir_x < 0) //W
			data->cast.wall_color = BLUE;
		else //E
			data->cast.wall_color = YELLOW;
	}
	ft_draw_vertical_line(data, x);
}

void	wall_texture(t_data *data, int x)
{
	double	wall_x;
	int		texture_x;

	if (data->cast.side == 1)
		wall_x = data->cast.pov_x + data->cast.perpend_wall_dist
			* data->cast.ray_dir_x;
	else
		wall_x = data->cast.pov_y + data->cast.perpend_wall_dist
			* data->cast.ray_dir_y;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)TEX_SIZE);
	if (data->cast.side == 1 && data->cast.ray_dir_y > 0)
		texture_x = TEX_SIZE - texture_x - 1;
	if (data->cast.side == 0 && data->cast.ray_dir_x > 0)
		texture_x = TEX_SIZE - texture_x - 1;
	wall_texture_step(data, x, texture_x);
}

void 	wall_texture_step(t_data *data, int x, int texture_x)
{
	double	texture_step;
	double	texture_pos;
	int		texture_y;
	int		y;
	
	texture_step = 1.0 * TEX_SIZE / data->cast.line_height;
	texture_pos = (data->cast.draw_start - (HEIGHT / 2)
			+ (data->cast.line_height / 2)) * texture_step;
	y = data->cast.draw_start;
	while (y < data->cast.draw_end)
	{
		texture_y = (int)texture_pos & (TEX_SIZE - 1);
		texture_pos += texture_step;
		get_wall_texture_pixel(data, texture_x, texture_y);
		ft_draw_pixel(data, x, y, data->cast.wall_color);
		y++;
	} 	
}

void	get_wall_texture_pixel(t_data *data, int texture_x, int texture_y)
{
	if (data->cast.side == 1 && data->cast.ray_dir_y < 0) //N
		data->cast.wall_color = *(unsigned int *)(data->n_textr.pix_addr + texture_y * data->n_textr.line_len
		+ texture_x * (data->n_textr.bpp / 8));
	else if (data->cast.side == 1 && data->cast.ray_dir_y >= 0) //S
		data->cast.wall_color = *(unsigned int *)(data->s_textr.pix_addr + texture_y * data->s_textr.line_len
		+ texture_x * (data->s_textr.bpp / 8));
	else if (data->cast.side == 0 && data->cast.ray_dir_x < 0) //W
		data->cast.wall_color = *(unsigned int *)(data->w_textr.pix_addr + texture_y * data->w_textr.line_len
		+ texture_x * (data->w_textr.bpp / 8));
	else if (data->cast.side == 0 && data->cast.ray_dir_x >= 0) //E
		data->cast.wall_color = *(unsigned int *)(data->e_textr.pix_addr + texture_y * data->e_textr.line_len
		+ texture_x * (data->e_textr.bpp / 8));
}
