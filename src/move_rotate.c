/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:00:04 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/05 10:57:46 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_with_keys(t_data *data)
{
	double	dir;

	dir = 0;
	if (data->move.rot_l == 1 && data->move.rot_r == 1)
		dir = 0;
	else if (data->move.rot_l == 1)
		dir = 1;
	else if (data->move.rot_r == 1)
		dir = -1;
	if (dir != 0)
		rotation_calcs(data, dir);
}

void	rotate_with_mouse(t_data *data)
{
	double	mouse_ratio;
	double	mouse_delta;

	mouse_delta = data->mouse.pos.x - data->mouse.old_x;
	mouse_ratio = (-data->mouse.offset_x / (WIDTH / 2))
		* DELTA_MULT - (mouse_delta / (WIDTH * 4));
	rotation_calcs(data, mouse_ratio);
	mlx_mouse_move(data->mlx.mlx_ptr, data->mlx.window, WIDTH / 2, HEIGHT / 2);
}

void	rotation_calcs(t_data *data, double rot_mult)
{
	double	old_dir_x;
	double	old_plane_x;

	rot_mult = -rot_mult;
	old_dir_x = data->cast.dir.x;
	old_plane_x = data->cast.plane.x;
	data->cast.dir.x = (data->cast.dir.x * cos(rot_mult * data->move.rot))
		- (data->cast.dir.y * sin(rot_mult * data->move.rot));
	data->cast.dir.y = (old_dir_x * sin(rot_mult * data->move.rot))
		+ (data->cast.dir.y * cos(rot_mult * data->move.rot));
	data->cast.plane.x = (data->cast.plane.x * cos(rot_mult * data->move.rot))
		- (data->cast.plane.y * sin(rot_mult * data->move.rot));
	data->cast.plane.y = (old_plane_x * sin(rot_mult * data->move.rot))
		+ (data->cast.plane.y * cos(rot_mult * data->move.rot));
}
