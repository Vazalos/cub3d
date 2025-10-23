/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:39:46 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/23 16:33:20 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	frame_time_and_speed(t_data *data)
{
	double	frame_duration;

	data->old_time = data->current_time;
	data->current_time = ft_get_time();
	frame_duration = (data->current_time - data->old_time) / 1000.0;
	data->fps = 1 / frame_duration;
	if (data->fps > 10)
		data->move.speed = frame_duration * SPEED_MOD;
	else
		data->move.speed = 0.1 * SPEED_MOD;
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
		if (x == data->mouse.pos.x && data->print_debug_info == 1)
			print_coords(data);
	}
	frame_time_and_speed(data);
	walk(data);
	rotate_with_keys(data);
	if (data->window_focus == 1)
		rotate_with_mouse(data);
	if (data->mmap.hide_minimap == 0)
		draw_minimap(data);
}
