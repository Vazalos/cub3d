/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:06:15 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/29 13:47:35 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	wall_color(t_data *data, int x)
{
	if (data->calc.side == 1)
	{
		if (data->calc.ray_dir_y < 0) //N
			data->calc.wall_color = RED;
		else //S
			data->calc.wall_color = GREEN;
	}
	else if (data->calc.side == 0)
	{
		if (data->calc.ray_dir_x < 0) //W
			data->calc.wall_color = BLUE;
		else //E
			data->calc.wall_color = YELLOW;
	}
	ft_draw_vertical_line(data, x);
}

void	wall_texture(t_data *data, int x)
{
	double	wall_x;
	int		texture_x;

	if (data->calc.side == 1)
		wall_x = data->calc.pov_x + data->calc.perpend_wall_dist
			* data->calc.ray_dir_x;
	else
		wall_x = data->calc.pov_y + data->calc.perpend_wall_dist
			* data->calc.ray_dir_y;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)TEX_SIZE);
	if (data->calc.side == 1 && data->calc.ray_dir_y > 0)
		texture_x = TEX_SIZE - texture_x - 1;
	if (data->calc.side == 0 && data->calc.ray_dir_x > 0)
		texture_x = TEX_SIZE - texture_x - 1;
	wall_texture_step(data, x, texture_x);
}

void 	wall_texture_step(t_data *data, int x, int texture_x)
{
	double	texture_step;
	double	texture_pos;
	int		texture_y;
	int		y;
	
	texture_step = 1.0 * TEX_SIZE / data->calc.line_height;
	texture_pos = (data->calc.draw_start - (HEIGHT / 2)
			+ (data->calc.line_height / 2)) * texture_step;
	y = data->calc.draw_start;
	while (y < data->calc.draw_end)
	{
		texture_y = (int)texture_pos & (TEX_SIZE - 1);
		texture_pos += texture_step;
		get_wall_texture_pixel(data, texture_x, texture_y);
		ft_draw_pixel(data, x, y, data->calc.wall_color);
		y++;
	} 	
}

void	get_wall_texture_pixel(t_data *data, int texture_x, int texture_y)
{
	if (data->calc.side == 1 && data->calc.ray_dir_y < 0) //N
		data->calc.wall_color = *(unsigned int *)(data->n_textr.pix_addr + texture_y * data->n_textr.line_len
		+ texture_x * (data->n_textr.bpp / 8));
	else if (data->calc.side == 1 && data->calc.ray_dir_y >= 0) //S
		data->calc.wall_color = *(unsigned int *)(data->s_textr.pix_addr + texture_y * data->s_textr.line_len
		+ texture_x * (data->s_textr.bpp / 8));
	else if (data->calc.side == 0 && data->calc.ray_dir_x < 0) //W
		data->calc.wall_color = *(unsigned int *)(data->w_textr.pix_addr + texture_y * data->w_textr.line_len
		+ texture_x * (data->w_textr.bpp / 8));
	else if (data->calc.side == 0 && data->calc.ray_dir_x >= 0) //E
		data->calc.wall_color = *(unsigned int *)(data->e_textr.pix_addr + texture_y * data->e_textr.line_len
		+ texture_x * (data->e_textr.bpp / 8));
}
