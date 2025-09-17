/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:05:10 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/17 17:06:51 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	walk(t_data *data, int map[][10])
{
	if (data->move.front == 1)
	{
		if(map[(int)(data->calc.pov_x + (data->calc.dir_x * data->move.speed))][(int)data->calc.pov_y] == 0)
			data->calc.pov_x += data->calc.dir_x * data->move.speed;
		if(map[(int)data->calc.pov_x][(int)(data->calc.pov_y + (data->calc.dir_y * data->move.speed))] == 0)
			data->calc.pov_y += data->calc.dir_y * data->move.speed;
	}
	if (data->move.back == 1)
	{
		if(map[(int)(data->calc.pov_x - (data->calc.dir_x * data->move.speed))][(int)data->calc.pov_y] == 0)
			data->calc.pov_x -= data->calc.dir_x * data->move.speed;
		if(map[(int)data->calc.pov_x][(int)(data->calc.pov_y - (data->calc.dir_y * data->move.speed))] == 0)
			data->calc.pov_y -= data->calc.dir_y * data->move.speed;
	}
	if (data->move.left == 1)
	{
		if(map[(int)(data->calc.pov_x - (data->calc.dir_y * data->move.speed))][(int)data->calc.pov_y] == 0)
			data->calc.pov_x -= data->calc.dir_y * data->move.speed;
		if(map[(int)data->calc.pov_x][(int)(data->calc.pov_y + (data->calc.dir_x * data->move.speed))] == 0)
			data->calc.pov_y += data->calc.dir_x * data->move.speed;
	}
	if (data->move.right == 1)
	{
		if(map[(int)(data->calc.pov_x + (data->calc.dir_y * data->move.speed))][(int)data->calc.pov_y] == 0)
			data->calc.pov_x += data->calc.dir_y * data->move.speed;
		if(map[(int)data->calc.pov_x][(int)(data->calc.pov_y - (data->calc.dir_x * data->move.speed))] == 0)
			data->calc.pov_y -= data->calc.dir_x * data->move.speed;
	}
}

void	rotate(t_data *data)
{
	double old_dir_x;
	double old_plane_x;
	
	if (data->move.rot_l == 1)
	{
		old_dir_x = data->calc.dir_x;
		old_plane_x = data->calc.plane_x;
		data->calc.dir_x = (data->calc.dir_x * cos(data->move.rotation)) - (data->calc.dir_y * sin(data->move.rotation));
		data->calc.dir_y = (old_dir_x * sin(data->move.rotation)) + (data->calc.dir_y * cos(data->move.rotation)); 
		data->calc.plane_x = (data->calc.plane_x * cos(data->move.rotation)) - (data->calc.plane_y * sin(data->move.rotation));
		data->calc.plane_y = (old_plane_x * sin(data->move.rotation)) + (data->calc.plane_y * cos(data->move.rotation));
	}
	if (data->move.rot_r == 1)
	{
		old_dir_x = data->calc.dir_x;
		old_plane_x = data->calc.plane_x;
		data->calc.dir_x = (data->calc.dir_x * cos(-data->move.rotation)) - (data->calc.dir_y * sin(-data->move.rotation));
		data->calc.dir_y = (old_dir_x * sin(-data->move.rotation)) + (data->calc.dir_y * cos(-data->move.rotation)); 
		data->calc.plane_x = (data->calc.plane_x * cos(-data->move.rotation)) - (data->calc.plane_y * sin(-data->move.rotation));
		data->calc.plane_y = (old_plane_x * sin(-data->move.rotation)) + (data->calc.plane_y * cos(-data->move.rotation));
	}	
}