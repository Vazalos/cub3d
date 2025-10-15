/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:00:04 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/15 14:00:14 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
