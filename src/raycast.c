/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:39:46 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/14 13:50:05 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calc_acceleration(t_data *data)
{
	double	max_accel = 0.1;
	double	accel_step = 0.0001;
	
	if (data->move.front == 0 && data->move.accel_f > 0)
		data->move.accel_f -= data->move.accel_f + accel_step;
	else if (data->move.front == 1 && data->move.accel_f < max_accel)
		data->move.accel_f += data->move.accel_f + accel_step;
	if (data->move.accel_f > max_accel)
		data->move.accel_f = max_accel;
	else if (data->move.accel_f < 0)
		data->move.accel_f = 0;
	
}

void	frame_time_and_speed(t_data *data)
{
	double frame_duration;
	
	data->old_time = data->time;
	data->time = ft_get_time();
	frame_duration = (data->time - data->old_time) / 1000.0;
	data->fps = 1 / frame_duration;
	calc_acceleration(data);
	data->move.speed = frame_duration * SPEED_MOD;
	data->move.rot = frame_duration * ROTATION_MOD;
	//print_fps(data->fps);
}

void	ft_raycast(t_data *data)
{
	int	x;
	/*
	char	map[10][19] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};
	*/

	x = -1;
	while (++x < WIDTH)
	{
		get_base_coords(data, x);
		dist_per_square_x(data);
		dist_per_square_y(data);
		wall_hit_dist(data);
		wall_height(data);
		wall_texture(data, x);
		if (x == data->mouse.x)
			print_coords(data);
	}
	frame_time_and_speed(data);
	walk_front_and_back(data);
	walk_left_and_right(data);
	rotate_player(data);
	rotate_with_mouse(data);
	mlx_mouse_move(data->mlx.mlx_ptr, data->mlx.window, WIDTH / 2, HEIGHT / 2);

	//draw_minimap(data); //change to render afterwards
}
