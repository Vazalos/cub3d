/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:39:46 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/21 14:35:37 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
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
	//calc_acceleration(data);
*/

void	frame_time_and_speed(t_data *data)
{
	double	frame_duration;

	data->old_time = data->time;
	data->time = ft_get_time();
	frame_duration = (data->time - data->old_time) / 1000.0;
	data->fps = 1 / frame_duration;
	data->move.speed = frame_duration * SPEED_MOD;
	data->move.rot = frame_duration * ROTATION_MOD;
}

void	ft_raycast(t_data *data)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		get_base_coords(data, x);
		dist_per_square_x(data);
		dist_per_square_y(data);
		wall_hit_dist(data);
		wall_height(data);
		wall_texture(data, x);
		if (x == data->mouse.x && data->print_debug_info == 1)
			print_coords(data);
	}
	frame_time_and_speed(data);
	walk(data);
	rotate_player(data);
	rotate_with_mouse(data);
	mlx_mouse_move(data->mlx.mlx_ptr, data->mlx.window, WIDTH / 2, HEIGHT / 2);
	if (data->mmap.hide_minimap == 0)
		draw_minimap(data);
}
