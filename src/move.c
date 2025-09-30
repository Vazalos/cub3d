/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:05:10 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/30 15:46:21 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	frame_time_and_speed(t_data *data)
{
	data->old_time = data->time;
	data->time = ft_get_time();
	data->frame_time = (data->time - data->old_time) / 1000.0;
	//print_fps(data->frame_time);
	data->move.speed = data->frame_time * 5.0;
	data->move.rotation = data->frame_time * 3.0;
}

void	walk_front_and_back(t_data *data, int map[][10])
{
	if (data->move.front == 1)
	{
		if (map[(int)(data->calc.pov_x + (data->calc.dir_x
					* data->move.speed))][(int)data->calc.pov_y] == 0)
			data->calc.pov_x += data->calc.dir_x * data->move.speed;
		if (map[(int)data->calc.pov_x][(int)(data->calc.pov_y
			+ (data->calc.dir_y * data->move.speed))] == 0)
			data->calc.pov_y += data->calc.dir_y * data->move.speed;
	}
	if (data->move.back == 1)
	{
		if (map[(int)(data->calc.pov_x - (data->calc.dir_x
					* data->move.speed))][(int)data->calc.pov_y] == 0)
			data->calc.pov_x -= data->calc.dir_x * data->move.speed;
		if (map[(int)data->calc.pov_x][(int)(data->calc.pov_y
			- (data->calc.dir_y * data->move.speed))] == 0)
			data->calc.pov_y -= data->calc.dir_y * data->move.speed;
	}
}

void	walk_left_and_right(t_data *data, int map[][10])
{
	if (data->move.left == 1)
	{
		if (map[(int)(data->calc.pov_x - (data->calc.dir_y
					* data->move.speed))][(int)data->calc.pov_y] == 0)
			data->calc.pov_x -= data->calc.dir_y * data->move.speed;
		if (map[(int)data->calc.pov_x][(int)(data->calc.pov_y
			+ (data->calc.dir_x * data->move.speed))] == 0)
			data->calc.pov_y += data->calc.dir_x * data->move.speed;
	}
	if (data->move.right == 1)
	{
		if (map[(int)(data->calc.pov_x + (data->calc.dir_y
					* data->move.speed))][(int)data->calc.pov_y] == 0)
			data->calc.pov_x += data->calc.dir_y * data->move.speed;
		if (map[(int)data->calc.pov_x][(int)(data->calc.pov_y
			- (data->calc.dir_x * data->move.speed))] == 0)
			data->calc.pov_y -= data->calc.dir_x * data->move.speed;
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
		old_dir_x = data->calc.dir_x;
		old_plane_x = data->calc.plane_x;
		data->calc.dir_x = (data->calc.dir_x * cos(l * data->move.rotation))
			- (data->calc.dir_y * sin(l * data->move.rotation));
		data->calc.dir_y = (old_dir_x * sin(l * data->move.rotation))
			+ (data->calc.dir_y * cos(l * data->move.rotation));
		data->calc.plane_x = (data->calc.plane_x * cos(l * data->move.rotation))
			- (data->calc.plane_y * sin(l * data->move.rotation));
		data->calc.plane_y = (old_plane_x * sin(l * data->move.rotation))
			+ (data->calc.plane_y * cos(l * data->move.rotation));
	}
}

void	rotate_with_mouse(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double 	mouse_ratio; //dummy var
	double	mouse_delta;

	mouse_delta = data->calc.mouse_x - data->calc.old_mouse_x;
	if (mouse_delta < 0)
		mouse_delta = -mouse_delta;
	mouse_ratio = (-data->calc.offset_mouse_x / (WIDTH / 2)) * (mouse_delta * DELTA_MULT);

	old_dir_x = data->calc.dir_x;
	old_plane_x = data->calc.plane_x;
	data->calc.dir_x = (data->calc.dir_x * cos(mouse_ratio * data->move.rotation))
		- (data->calc.dir_y * sin(mouse_ratio * data->move.rotation));
	data->calc.dir_y = (old_dir_x * sin(mouse_ratio * data->move.rotation))
		+ (data->calc.dir_y * cos(mouse_ratio * data->move.rotation));
	data->calc.plane_x = (data->calc.plane_x * cos(mouse_ratio * data->move.rotation))
		- (data->calc.plane_y * sin(mouse_ratio * data->move.rotation));
	data->calc.plane_y = (old_plane_x * sin(mouse_ratio * data->move.rotation))
		+ (data->calc.plane_y * cos(mouse_ratio * data->move.rotation));
}