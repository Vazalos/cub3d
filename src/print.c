/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:42:51 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/14 13:51:49 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_fps_in_window(t_data *data)
{
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.window, 10, HEIGHT - 10,
		WHITE, ft_itoa(data->fps));
}

void	print_fps(int fps)
{
	printf("FPS: %i\n", fps);
}

void	print_coords(t_data *data)
{
	printf(
		"current map square %c\n"
		"pov_x %.2f\npov_y %.2f\n"
		"dir_x %.2f\ndir_y %.2f\n"
		"plane_x %.2f\nplane_y %.2f\n\n"
		
		"mouse_y %.2f\nmouse_x %.2f\n"
		"old_mouse_x %.2f\n"
		"mousex - oldmousex = %.2f\n"
		
		"camera_x %.2f\n"
		"ray_dir_x %.2f\nray_dir_y %.2f\n"
		"map_x %i\nmap_y %i\n"
		"sidedist_x %.2f\nsidedist_y %.2f\n"
		"deltadist_x %.2f\ndeltadist_y %.2f\n"
		"perpend_wall_dist %.2f\nstep_x %i\nstep_y %i\n"
		"hit %i\nside %i\n"
		"line_h %i\ndraw_start %i\ndraw_end %i\n"
		"color %X OR %u\n\n",
		data->map->map[(int)data->cast.pov_y][(int)data->cast.pov_x],
		data->cast.pov_x, data->cast.pov_y,
		data->cast.dir_x, data->cast.dir_y,
		data->cast.plane_x, data->cast.plane_y,
		
		data->mouse.y, data->mouse.x,
		data->mouse.old_x,
		data->mouse.old_x - data->mouse.x,
		
		data->cast.camera_x,
		data->cast.ray_dir_x, data->cast.ray_dir_y,
		data->cast.map_x, data->cast.map_y,
		data->cast.side_dist_x, data->cast.side_dist_y,
		data->cast.delta_dist_x, data->cast.delta_dist_y,
		data->cast.perpend_wall_dist, data->cast.step_x, data->cast.step_y,
		data->cast.wall_hit, data->cast.side,
		data->cast.line_height, data->cast.draw_start, data->cast.draw_end,
		data->cast.wall_color, data->cast.wall_color);
}
