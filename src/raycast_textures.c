/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:06:15 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/23 15:00:13 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	wall_color(t_data *data)
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
		//color part
	if (data->calc.side == 1 && data->calc.ray_dir_y < 0) //N
		data->calc.wall_color = RED;
	else if (data->calc.side == 1 && data->calc.ray_dir_y >= 0) //S
		data->calc.wall_color = GREEN;
	else if (data->calc.side == 0 && data->calc.ray_dir_x < 0) //W
		data->calc.wall_color = BLUE;
	else if (data->calc.side == 0 && data->calc.ray_dir_x >= 0) //E
		data->calc.wall_color = YELLOW;
}
	/*
	if (map[data->calc.map_x][data->calc.map_y] == 1)
		data->calc.wall_color = RED;
	else if (map[data->calc.map_x][data->calc.map_y] == 2)
		data->calc.wall_color = GREEN;
	else if (map[data->calc.map_x][data->calc.map_y] == 3)
		data->calc.wall_color = BLUE;
	else
		data->calc.wall_color = YELLOW;
	if (data->calc.side == 1)
		data->calc.wall_color = data->calc.wall_color / 2;
	*/

void	wall_texture(t_data *data)
{
	double	wall_x;
	int		texture_x;
	double	texture_step;
	double	texture_pos;
	int		texture_y;
	int		y;
	unsigned int	tex_color;

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
	texture_step = 1.0 * TEX_SIZE / data->calc.line_height;
	texture_pos = (data->calc.draw_start - (HEIGHT / 2)
			+ (data->calc.line_height / 2)) * texture_step;
	y = data->calc.draw_start;
	while (y < data->calc.draw_end)
	{
		texture_y = (int)texture_pos & (TEX_SIZE - 1);
		texture_pos += texture_pos;
		//Uint32 color = texture[texNum][texHeight * texY + texX];
		tex_color = // divide by viewing side;
		y++;
	} 
}
