/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:08:01 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/18 12:07:35 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dist_per_square_x(t_data *data)
{
	if (data->calc.ray_dir_x == 0)
		data->calc.delta_dist_x = HUGE_VAL;
	else
		data->calc.delta_dist_x = fabs(1 / data->calc.ray_dir_x);
	if (data->calc.ray_dir_x < 0)
	{
		data->calc.step_x = -1;
		data->calc.side_dist_x = (data->calc.pov_x - data->calc.map_x)
			* data->calc.delta_dist_x;
	}
	else
	{
		data->calc.step_x = 1;
		data->calc.side_dist_x = (data->calc.map_x + 1.0 - data->calc.pov_x)
			* data->calc.delta_dist_x;
	}
}

void	dist_per_square_y(t_data *data)
{
	if (data->calc.ray_dir_y == 0)
		data->calc.delta_dist_y = HUGE_VAL;
	else
		data->calc.delta_dist_y = fabs(1 / data->calc.ray_dir_y);
	if (data->calc.ray_dir_y < 0)
	{
		data->calc.step_y = -1;
		data->calc.side_dist_y = (data->calc.pov_y - data->calc.map_y)
			* data->calc.delta_dist_y;
	}
	else
	{
		data->calc.step_y = 1;
		data->calc.side_dist_y = (data->calc.map_y + 1.0 - data->calc.pov_y)
			* data->calc.delta_dist_y;
	}
}

void	wall_hit_dist(t_data *data, int map[][10]) // change map later
{
	data->calc.wall_hit = 0;
	while (data->calc.wall_hit == 0)
	{
		if (data->calc.side_dist_x < data->calc.side_dist_y)
		{
			data->calc.side_dist_x += data->calc.delta_dist_x;
			data->calc.map_x += data->calc.step_x;
			data->calc.side = 0;
		}
		else
		{
			data->calc.side_dist_y += data->calc.delta_dist_y;
			data->calc.map_y += data->calc.step_y;
			data->calc.side = 1;
		}
		if (map[data->calc.map_x][data->calc.map_y] > 0)
			data->calc.wall_hit = 1;
	}
	if (data->calc.side == 0)
		data->calc.perpend_wall_dist = (data->calc.side_dist_x
				- data->calc.delta_dist_x);
	else
		data->calc.perpend_wall_dist = (data->calc.side_dist_y
				- data->calc.delta_dist_y);
}

void	wall_height_and_color(t_data *data, int map[][10]) // change map later
{
	data->calc.line_height = (int)(HEIGHT / data->calc.perpend_wall_dist);
	data->calc.draw_start = (-data->calc.line_height / 2) + (HEIGHT / 2);
	if (data->calc.draw_start < 0)
		data->calc.draw_start = 0;
	data->calc.draw_end = (data->calc.line_height / 2) + (HEIGHT / 2);
	if (data->calc.draw_end >= HEIGHT)
		data->calc.draw_end = HEIGHT - 1;
	if (map[data->calc.map_x][data->calc.map_y] == 0)
		data->calc.wall_color = PURPLE;
	else if (map[data->calc.map_x][data->calc.map_y] == 1)
		data->calc.wall_color = RED;
	else if (map[data->calc.map_x][data->calc.map_y] == 2)
		data->calc.wall_color = GREEN;
	else if (map[data->calc.map_x][data->calc.map_y] == 3)
		data->calc.wall_color = BLUE;
	else
		data->calc.wall_color = YELLOW;
	if (data->calc.side == 1)
		data->calc.wall_color = data->calc.wall_color / 3;
}
