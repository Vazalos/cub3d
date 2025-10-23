/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:08:01 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/23 11:05:46 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_base_coords(t_data *data, int x)
{
	data->cast.camera_x = 2 * x / (double)WIDTH - 1;
	data->cast.ray_dir.x = data->cast.dir.x
		+ data->cast.plane.x * data->cast.camera_x;
	data->cast.ray_dir.y = data->cast.dir.y
		+ data->cast.plane.y * data->cast.camera_x;
	data->cast.map.x = (int)data->cast.pov.x;
	data->cast.map.y = (int)data->cast.pov.y;
}

void	dist_per_square_x(t_data *data)
{
	if (data->cast.ray_dir.x == 0)
		data->cast.delta_dist.x = HUGE_VAL;
	else
		data->cast.delta_dist.x = fabs(1 / data->cast.ray_dir.x);
	if (data->cast.ray_dir.x < 0)
	{
		data->cast.step.x = -1;
		data->cast.side_dist.x = (data->cast.pov.x - data->cast.map.x)
			* data->cast.delta_dist.x;
	}
	else
	{
		data->cast.step.x = 1;
		data->cast.side_dist.x = (data->cast.map.x + 1.0 - data->cast.pov.x)
			* data->cast.delta_dist.x;
	}
}

void	dist_per_square_y(t_data *data)
{
	if (data->cast.ray_dir.y == 0)
		data->cast.delta_dist.y = HUGE_VAL;
	else
		data->cast.delta_dist.y = fabs(1 / data->cast.ray_dir.y);
	if (data->cast.ray_dir.y < 0)
	{
		data->cast.step.y = -1;
		data->cast.side_dist.y = (data->cast.pov.y - data->cast.map.y)
			* data->cast.delta_dist.y;
	}
	else
	{
		data->cast.step.y = 1;
		data->cast.side_dist.y = (data->cast.map.y + 1.0 - data->cast.pov.y)
			* data->cast.delta_dist.y;
	}
}

void	wall_hit_dist(t_data *data)
{
	data->cast.wall_hit = 0;
	while (data->cast.wall_hit == 0)
	{
		if (data->cast.side_dist.x < data->cast.side_dist.y)
		{
			data->cast.side_dist.x += data->cast.delta_dist.x;
			data->cast.map.x += data->cast.step.x;
			data->cast.side = 0;
		}
		else
		{
			data->cast.side_dist.y += data->cast.delta_dist.y;
			data->cast.map.y += data->cast.step.y;
			data->cast.side = 1;
		}
		if (data->map->map[data->cast.map.y][data->cast.map.x] == '1')
			data->cast.wall_hit = 1;
	}
	if (data->cast.side == 0)
		data->cast.perpend_wall_dist = (data->cast.side_dist.x
				- data->cast.delta_dist.x);
	else
		data->cast.perpend_wall_dist = (data->cast.side_dist.y
				- data->cast.delta_dist.y);
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
