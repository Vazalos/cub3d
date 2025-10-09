/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:05:10 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/09 16:31:53 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	walk_front_and_back(t_data *data)
{
	if (data->move.front == 1)
	{
		if (data->map->map[(int)(data->cast.pov_y + (data->cast.dir_y
					* data->move.speed))][(int)data->cast.pov_x] == 0)
			data->cast.pov_y += data->cast.dir_y * data->move.speed;
		if (data->map->map[(int)data->cast.pov_y][(int)(data->cast.pov_x
			+ (data->cast.dir_x * data->move.speed))] == 0)
			data->cast.pov_x += data->cast.dir_x * data->move.speed;
	}
	/*if (data->move.accel_f > 0)
	{
		if (data->map->map[(int)(data->cast.pov_y + (data->cast.dir_y
					* data->move.speed) + (data->cast.dir_y * data->move.accel_f))][(int)data->cast.pov_x] == 0)
			data->cast.pov_y += (data->cast.dir_y * data->move.speed) + (data->cast.dir_y * data->move.accel_f);
		if (data->map->map[(int)data->cast.pov_y][(int)(data->cast.pov_x
			+ (data->cast.dir_x * data->move.speed) + (data->cast.dir_x * data->move.accel_f))] == 0)
			data->cast.pov_x += (data->cast.dir_x * data->move.speed) + (data->cast.dir_x * data->move.accel_f);
	}*/
	if (data->move.back == 1)
	{
		if (data->map->map[(int)(data->cast.pov_y - (data->cast.dir_y
					* data->move.speed))][(int)data->cast.pov_x] == 0)
			data->cast.pov_y -= data->cast.dir_y * data->move.speed;
		if (data->map->map[(int)data->cast.pov_y][(int)(data->cast.pov_x
			- (data->cast.dir_x * data->move.speed))] == 0)
			data->cast.pov_x -= data->cast.dir_x * data->move.speed;
	}
}

void	walk_left_and_right(t_data *data)
{
	if (data->move.right == 1)
	{
		if (data->map->map[(int)(data->cast.pov_y - (data->cast.dir_x
					* data->move.speed))][(int)data->cast.pov_x] == 0)
			data->cast.pov_y -= data->cast.dir_x * data->move.speed;
		if (data->map->map[(int)data->cast.pov_y][(int)(data->cast.pov_x
			+ (data->cast.dir_y * data->move.speed))] == 0)
			data->cast.pov_x += data->cast.dir_y * data->move.speed;
	}
	if (data->move.left == 1)
	{
		//if (data->map->map[(int)(data->cast.pov_y + (data->cast.dir_x
		//			* data->move.speed))][(int)data->cast.pov_x] == 0)
			data->cast.pov_y += data->cast.dir_x * data->move.speed;
		//if (data->map->map[(int)data->cast.pov_y][(int)(data->cast.pov_x
		//	- (data->cast.dir_y * data->move.speed))] == 0)
			data->cast.pov_x -= data->cast.dir_y * data->move.speed;
	}
}

void	rotate_player(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	int		l;

	l = 0;
	if (data->move.rot_l == 1 && data->move.rot_r == 1)
		l = 0;
	else if (data->move.rot_l == 1)
		l = 1;
	else if (data->move.rot_r == 1)
		l = -1;
	if (l != 0)
	{
		old_dir_x = data->cast.dir_x;
		old_plane_x = data->cast.plane_x;
		data->cast.dir_x = (data->cast.dir_x * cos(l * data->move.rot))
			- (data->cast.dir_y * sin(l * data->move.rot));
		data->cast.dir_y = (old_dir_x * sin(l * data->move.rot))
			+ (data->cast.dir_y * cos(l * data->move.rot));
		data->cast.plane_x = (data->cast.plane_x * cos(l * data->move.rot))
			- (data->cast.plane_y * sin(l * data->move.rot));
		data->cast.plane_y = (old_plane_x * sin(l * data->move.rot))
			+ (data->cast.plane_y * cos(l * data->move.rot));
	}
}

void	rotate_with_mouse(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	mouse_rate;
	double	mouse_delta;

	mouse_delta = 0;
	mouse_rate = 0;
	mouse_delta = data->mouse.x - data->mouse.old_x;
	if (mouse_delta < 0)
		mouse_delta = -mouse_delta;
	mouse_rate = (-data->mouse.offset_x / (WIDTH / 2))
		* (mouse_delta * DELTA_MULT);
	old_dir_x = data->cast.dir_x;
	old_plane_x = data->cast.plane_x;
	data->cast.dir_x = (data->cast.dir_x * cos(mouse_rate * data->move.rot))
		- (data->cast.dir_y * sin(mouse_rate * data->move.rot));
	data->cast.dir_y = (old_dir_x * sin(mouse_rate * data->move.rot))
		+ (data->cast.dir_y * cos(mouse_rate * data->move.rot));
	data->cast.plane_x = (data->cast.plane_x * cos(mouse_rate * data->move.rot))
		- (data->cast.plane_y * sin(mouse_rate * data->move.rot));
	data->cast.plane_y = (old_plane_x * sin(mouse_rate * data->move.rot))
		+ (data->cast.plane_y * cos(mouse_rate * data->move.rot));
}
