/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:39:46 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/01 16:39:49 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	frame_time_and_speed(t_data *data)
{
	double frame_duration;
	
	data->old_time = data->time;
	data->time = ft_get_time();
	frame_duration = (data->time - data->old_time) / 1000.0;
	data->fps = 1 / frame_duration;
	print_fps(data->fps);
	data->move.speed = frame_duration * 5.0;
	data->move.rot = frame_duration * 3.0;
}

void	ft_raycast(t_data *data)
{
	int	x;
	int	map[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 4, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 2, 0, 0, 0, 1},
	{1, 0, 0, 0, 3, 1, 3, 0, 0, 1},
	{1, 0, 0, 0, 0, 2, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	x = -1;
	//data->mouse.old_x = data->mouse.x;
	while (++x < WIDTH)
	{
		get_base_coords(data, x);
		dist_per_square_x(data);
		dist_per_square_y(data);
		wall_hit_dist(data, map);
		wall_height(data);
		wall_texture(data, x);
		//if (x == data->mouse.x)
		//	print_coords(data);
	}
	frame_time_and_speed(data);
	walk_front_and_back(data, map);
	walk_left_and_right(data, map);
	rotate_player(data);
	rotate_with_mouse(data);
	mlx_mouse_move(data->mlx.mlx_ptr, data->mlx.window, WIDTH / 2, HEIGHT / 2);
}
