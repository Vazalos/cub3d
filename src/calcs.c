/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:39:46 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/15 17:14:42 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_vertical(t_data *data, int x)
{
	int	y;

	y = data->draw_start;
	while (y < data->draw_end) //  <=?
	{
		ft_draw_pixel(data, x, y, data->color);
		y++;
	}
}

void	ft_raycast(t_data *data)
{
	int	x;
	int	map[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	x = 0;
	data->draw_map = 1;
	while (data->draw_map == 1) //CHANGE
	{
		while (x < WIDTH)
		{
			data->camera_x = 2 * x / (double)WIDTH - 1;
			data->ray_dir_x = data->view.dir_x
				+ data->view.plane_x * data->camera_x;
			data->ray_dir_y = data->view.dir_y
				+ data->view.plane_y * data->camera_x;
			data->map_x = (int)data->view.pov_x;
			data->map_y = (int)data->view.pov_y;
			if (data->ray_dir_x == 0)
				data->delta_dist_x = HUGE_VAL;
			else
				data->delta_dist_x = fabs(1 / data->ray_dir_x);
			if (data->ray_dir_y == 0)
				data->delta_dist_y = HUGE_VAL;
			else
				data->delta_dist_y = fabs(1 / data->ray_dir_y);
			data->wall_hit = 0;
			if (data->ray_dir_x < 0)
			{
				data->step_x = -1;
				data->side_dist_x = (data->view.pov_x - data->map_x)
					* data->delta_dist_x;
			}
			else
			{
				data->step_x = 1;
				data->side_dist_x = (data->map_x + 1.0 - data->view.pov_x)
					* data->delta_dist_x;
			}
			if (data->ray_dir_y < 0)
			{
				data->step_y = -1;
				data->side_dist_y = (data->view.pov_y - data->map_y)
					* data->delta_dist_y;
			}
			else
			{
				data->step_y = 1;
				data->side_dist_y = (data->map_y + 1.0 - data->view.pov_y)
					* data->delta_dist_y;
			}
			while (data->wall_hit == 0)
			{
				if (data->side_dist_x < data->side_dist_y)
				{
					data->side_dist_x += data->delta_dist_x;
					data->map_x += data->step_x;
					data->side = 0;
				}
				else
				{
					data->side_dist_y += data->delta_dist_y;
					data->map_y += data->step_y;
					data->side = 1;
				}
				if (map[data->map_x][data->map_y] > 0)
					data->wall_hit = 1;
			}
			if (data->side == 0)
				data->perpend_wall_dist = (data->side_dist_x
						- data->delta_dist_x);
			else
				data->perpend_wall_dist = (data->side_dist_y
						- data->delta_dist_y);
			data->line_height = (int)(HEIGHT / data->perpend_wall_dist);
			data->draw_start = (-data->line_height / 2) + (HEIGHT / 2);
			if (data->draw_start < 0)
				data->draw_start = 0;
			data->draw_end = (data->line_height / 2) + (HEIGHT / 2);
			if (data->draw_end >= HEIGHT)
				data->draw_end = HEIGHT - 1;
			if (map[data->map_x][data->map_y] == 0)
				data->color = PURPLE;
			else if (map[data->map_x][data->map_y] == 1)
				data->color = RED;
			else if (map[data->map_x][data->map_y] == 2)
				data->color = GREEN;
			else if (map[data->map_x][data->map_y] == 3)
				data->color = BLUE;
			else
				data->color = YELLOW;
			if (data->side == 1)
				data->color = data->color / 2;
			ft_draw_vertical(data, x);
			printf("camera_x %.2f\nraydist_x %.2f\nraydist_y %.2f\nmap_x %i\nmap_y %i\nsidedist_x %.2f\nsidedist_y %.2f\ndeltadist_x %.2f\ndeltadist_y %.2f\n"
				"perpend_wall_dist %.2f\nstep_x %i\nstep_y %i\nhit %i\nside %i\nline_h %i\ndraw_start %i\ndraw_end%i\ncolor %i\n\n",
				data->camera_x, data->ray_dir_x, data->ray_dir_y, data->map_x, data->map_y, data->side_dist_x, data->side_dist_y, data->delta_dist_x, data->delta_dist_y, data->perpend_wall_dist, data->step_x, data->step_y, data->wall_hit, data->side, data->line_height, data->draw_start, data->draw_end, data->color);
			x++;
		}
		data->draw_map = 0;
		//data->old_time = data->time;
		//data->time = ft_get_time();
		//double frame_time = (data->time - data->old_time) / 1000.0;
		//printf("%.2f\n", 1.0 / frame_time);
		//redraw - push to window;
		//cls - clear window;
		//double move_speed = frame_time = 5.0; UNUSED
		//double rot_speed = frame_time = 3.0; UNUSED
	}
}
		//keys missing here
