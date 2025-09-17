/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:42:51 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/17 16:56:18 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_fps(double frame_duration)
{
	printf("FPS %.0f\n", 1.0 / frame_duration);
}

void	print_coords(t_data *data)
{
	printf(
		"pov_x %.2f\npov_y %.2f\n"
		"dir_x %.2f\ndir_y %.2f\n"
		"plane_x %.2f\nplane_y %.2f\n\n"
		"camera_x %.2f\n"
		"raydist_x %.2f\nraydist_y %.2f\n"
		"map_x %i\nmap_y %i\n"
		"sidedist_x %.2f\nsidedist_y %.2f\n"
		"deltadist_x %.2f\ndeltadist_y %.2f\n"
		"perpend_wall_dist %.2f\n"
		"step_x %i\nstep_y %i\n"
		"hit %i\n"
		"side %i\n"
		"line_h %i\n"
		"draw_start %i\ndraw_end%i\n"
		"color %i\n\n",
		data->calc.pov_x,
		data->calc.pov_y,
		data->calc.dir_x,
		data->calc.dir_y,
		data->calc.plane_x,
		data->calc.plane_y,
		data->calc.camera_x, 
		data->calc.ray_dir_x, data->calc.ray_dir_y, 
		data->calc.map_x, data->calc.map_y, 
		data->calc.side_dist_x, data->calc.side_dist_y, 
		data->calc.delta_dist_x, data->calc.delta_dist_y, 
		data->calc.perpend_wall_dist,
		data->calc.step_x, data->calc.step_y, 
		data->calc.wall_hit,
		data->calc.side, 
		data->calc.line_height,
		data->calc.draw_start, data->calc.draw_end,
		data->calc.wall_color);
}