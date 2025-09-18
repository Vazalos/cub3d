/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:39:46 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/18 12:17:02 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_raycast(t_data *data)
{
	int	x;
	int	map[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 2, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
	{1, 0, 1, 0, 3, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	x = -1;
	while (++x < WIDTH)
	{
		get_base_coords(data, x);
		dist_per_square_x(data);
		dist_per_square_y(data);
		wall_hit_dist(data, map);
		wall_height_and_color(data, map);
		ft_draw_vertical(data, x);
		if (x == WIDTH / 2)
			print_coords(data);
	}
	frame_time_and_speed(data);
	walk_front_and_back(data, map);
	walk_left_and_right(data, map);
	rotate(data);
}

void	get_base_coords(t_data *data, int x)
{
	data->calc.camera_x = 2 * x / (double)WIDTH - 1;
	data->calc.ray_dir_x = data->calc.dir_x
		+ data->calc.plane_x * data->calc.camera_x;
	data->calc.ray_dir_y = data->calc.dir_y
		+ data->calc.plane_y * data->calc.camera_x;
	data->calc.map_x = (int)data->calc.pov_x;
	data->calc.map_y = (int)data->calc.pov_y;
}
