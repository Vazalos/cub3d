/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:08:01 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/20 17:03:33 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_base_coords(t_data *data, int x)
{
	data->cast.camera_x = 2 * x / (double)WIDTH - 1;
	data->cast.ray_dir_x = data->cast.dir_x
		+ data->cast.plane_x * data->cast.camera_x;
	data->cast.ray_dir_y = data->cast.dir_y
		+ data->cast.plane_y * data->cast.camera_x;
	data->cast.map_x = (int)data->cast.pov_x;
	data->cast.map_y = (int)data->cast.pov_y;
}

void	dist_per_square_x(t_data *data)
{
	if (data->cast.ray_dir_x == 0)
		data->cast.delta_dist_x = HUGE_VAL;
	else
		data->cast.delta_dist_x = fabs(1 / data->cast.ray_dir_x);
	if (data->cast.ray_dir_x < 0)
	{
		data->cast.step_x = -1;
		data->cast.side_dist_x = (data->cast.pov_x - data->cast.map_x)
			* data->cast.delta_dist_x;
	}
	else
	{
		data->cast.step_x = 1;
		data->cast.side_dist_x = (data->cast.map_x + 1.0 - data->cast.pov_x)
			* data->cast.delta_dist_x;
	}
}

void	dist_per_square_y(t_data *data)
{
	if (data->cast.ray_dir_y == 0)
		data->cast.delta_dist_y = HUGE_VAL;
	else
		data->cast.delta_dist_y = fabs(1 / data->cast.ray_dir_y);
	if (data->cast.ray_dir_y < 0)
	{
		data->cast.step_y = -1;
		data->cast.side_dist_y = (data->cast.pov_y - data->cast.map_y)
			* data->cast.delta_dist_y;
	}
	else
	{
		data->cast.step_y = 1;
		data->cast.side_dist_y = (data->cast.map_y + 1.0 - data->cast.pov_y)
			* data->cast.delta_dist_y;
	}
}

void	wall_hit_dist(t_data *data)
{
	data->cast.wall_hit = 0;
	while (data->cast.wall_hit == 0)
	{
		if (data->cast.side_dist_x < data->cast.side_dist_y)
		{
			data->cast.side_dist_x += data->cast.delta_dist_x;
			data->cast.map_x += data->cast.step_x;
			data->cast.side = 0;
		}
		else
		{
			data->cast.side_dist_y += data->cast.delta_dist_y;
			data->cast.map_y += data->cast.step_y;
			data->cast.side = 1;
		}
		if (data->map->map[data->cast.map_y][data->cast.map_x] == '1')
			data->cast.wall_hit = 1;
	}
	if (data->cast.side == 0)
		data->cast.perpend_wall_dist = (data->cast.side_dist_x
				- data->cast.delta_dist_x);
	else
		data->cast.perpend_wall_dist = (data->cast.side_dist_y
				- data->cast.delta_dist_y);
}

void	wall_height(t_data *data)
{
	data->cast.line_height = (int)(HEIGHT / data->cast.perpend_wall_dist);
	data->cast.draw_start = (-data->cast.line_height / 2) + (HEIGHT / 2);
	if (data->cast.draw_start < 0)
		data->cast.draw_start = 0;
	data->cast.draw_end = (data->cast.line_height / 2) + (HEIGHT / 2);
	if (data->cast.draw_end >= HEIGHT)
		data->cast.draw_end = HEIGHT;
}
