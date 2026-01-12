/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:00:04 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/12 14:03:45 by david-fe         ###   ########.fr       */
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
