/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:39:46 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/16 16:56:05 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_vertical(t_data *data, int x)
{
	int	y;
	int	horizon;

	horizon = HEIGHT / 2;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < data->calc.draw_start && y <= horizon)
			ft_draw_pixel(data, x, y, SKY);
		else if (y >= data->calc.draw_start && y <= data->calc.draw_end) 
			ft_draw_pixel(data, x, y, data->calc.wall_color);
		else if (y > data->calc.draw_end && y > horizon)
			ft_draw_pixel(data, x, y, FLOOR);
		y++;
	}
}

void	ft_raycast(t_data *data)
{
	int	x;
	int	map[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 2, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
	{1, 0, 1, 0, 3, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	x = 0;
	while (x < WIDTH)
	{
		data->calc.camera_x = 2 * x / (double)WIDTH - 1;
		data->calc.ray_dir_x = data->calc.dir_x
			+ data->calc.plane_x * data->calc.camera_x;
		data->calc.ray_dir_y = data->calc.dir_y
			+ data->calc.plane_y * data->calc.camera_x;
		data->calc.map_x = (int)data->calc.pov_x;
		data->calc.map_y = (int)data->calc.pov_y;
		if (data->calc.ray_dir_x == 0)
			data->calc.delta_dist_x = HUGE_VAL;
		else
			data->calc.delta_dist_x = fabs(1 / data->calc.ray_dir_x);
		if (data->calc.ray_dir_y == 0)
			data->calc.delta_dist_y = HUGE_VAL;
		else
			data->calc.delta_dist_y = fabs(1 / data->calc.ray_dir_y);
		data->calc.wall_hit = 0;
		if (data->calc.ray_dir_x < 0)
		{
			data->calc.step_x = -1;
			data->calc.side_dist_x = (data->calc.pov_x - data->calc.map_x)
				* data->calc.delta_dist_x;
		}
		else
		{
			data->calc.step_x = 1;
			data->calc.side_dist_x = (data->calc.map_x + 1.0 - data->calc.pov_x)
				* data->calc.delta_dist_x;
		}
		if (data->calc.ray_dir_y < 0)
		{
			data->calc.step_y = -1;
			data->calc.side_dist_y = (data->calc.pov_y - data->calc.map_y)
				* data->calc.delta_dist_y;
		}
		else
		{
			data->calc.step_y = 1;
			data->calc.side_dist_y = (data->calc.map_y + 1.0 - data->calc.pov_y)
				* data->calc.delta_dist_y;
		}
		while (data->calc.wall_hit == 0)
		{
			if (data->calc.side_dist_x < data->calc.side_dist_y)
			{
				data->calc.side_dist_x += data->calc.delta_dist_x;
				data->calc.map_x += data->calc.step_x;
				data->calc.side = 0;
			}
			else
			{
				data->calc.side_dist_y += data->calc.delta_dist_y;
				data->calc.map_y += data->calc.step_y;
				data->calc.side = 1;
			}
			if (map[data->calc.map_x][data->calc.map_y] > 0)
				data->calc.wall_hit = 1;
		}
		if (data->calc.side == 0)
			data->calc.perpend_wall_dist = (data->calc.side_dist_x
					- data->calc.delta_dist_x);
		else
			data->calc.perpend_wall_dist = (data->calc.side_dist_y
					- data->calc.delta_dist_y);
		data->calc.line_height = (int)(HEIGHT / data->calc.perpend_wall_dist);
		data->calc.draw_start = (-data->calc.line_height / 2) + (HEIGHT / 2);
		if (data->calc.draw_start < 0)
			data->calc.draw_start = 0;
		data->calc.draw_end = (data->calc.line_height / 2) + (HEIGHT / 2);
		if (data->calc.draw_end >= HEIGHT)
			data->calc.draw_end = HEIGHT - 1;
		if (map[data->calc.map_x][data->calc.map_y] == 0)
			data->calc.wall_color = PURPLE;
		else if (map[data->calc.map_x][data->calc.map_y] == 1)
			data->calc.wall_color = RED;
		else if (map[data->calc.map_x][data->calc.map_y] == 2)
			data->calc.wall_color = GREEN;
		else if (map[data->calc.map_x][data->calc.map_y] == 3)
			data->calc.wall_color = BLUE;
		else
			data->calc.wall_color = YELLOW;
		if (data->calc.side == 1)
			data->calc.wall_color = data->calc.wall_color / 2;
		ft_draw_vertical(data, x);
		/*printf("camera_x %.2f\nraydist_x %.2f\nraydist_y %.2f\nmap_x %i\nmap_y %i\nsidedist_x %.2f\nsidedist_y %.2f\ndeltadist_x %.2f\ndeltadist_y %.2f\n"
			"perpend_wall_dist %.2f\nstep_x %i\nstep_y %i\nhit %i\nside %i\nline_h %i\ndraw_start %i\ndraw_end%i\ncolor %i\n\n",
			data->calc.camera_x, data->calc.ray_dir_x, data->calc.ray_dir_y, data->calc.map_x, data->calc.map_y, data->calc.side_dist_x, data->calc.side_dist_y, data->calc.delta_dist_x, data->calc.delta_dist_y, data->calc.perpend_wall_dist, data->calc.step_x, data->calc.step_y, data->calc.wall_hit, data->calc.side, data->calc.line_height, data->calc.draw_start, data->calc.draw_end, data->calc.wall_color);
		*/
		x++;
	}
	data->old_time = data->time;
	data->time = ft_get_time();
	data->frame_time = (data->time - data->old_time) / 1000.0;
	printf("FPS %.2f\n", 1.0 / data->frame_time);
	data->move.speed = data->frame_time * 5.0; 
	data->move.rotation = data->frame_time * 3.0;

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
	double old_dir_x;
	double old_plane_x;
	if (data->move.left == 1)
	{
		old_dir_x = data->calc.dir_x;
		old_plane_x = data->calc.plane_x;
		data->calc.dir_x = (data->calc.dir_x * cos(data->move.rotation)) - (data->calc.dir_y * sin(data->move.rotation));
		data->calc.dir_y = (old_dir_x * sin(data->move.rotation)) + (data->calc.dir_y * cos(data->move.rotation)); 
		data->calc.plane_x = (data->calc.plane_x * cos(data->move.rotation)) - (data->calc.plane_y * sin(data->move.rotation));
		data->calc.plane_y = (old_plane_x * sin(data->move.rotation)) + (data->calc.plane_y * cos(data->move.rotation));
	}
	if (data->move.right == 1)
	{
		old_dir_x = data->calc.dir_x;
		old_plane_x = data->calc.plane_x;
		data->calc.dir_x = (data->calc.dir_x * cos(-data->move.rotation)) - (data->calc.dir_y * sin(-data->move.rotation));
		data->calc.dir_y = (old_dir_x * sin(-data->move.rotation)) + (data->calc.dir_y * cos(-data->move.rotation)); 
		data->calc.plane_x = (data->calc.plane_x * cos(-data->move.rotation)) - (data->calc.plane_y * sin(-data->move.rotation));
		data->calc.plane_y = (old_plane_x * sin(-data->move.rotation)) + (data->calc.plane_y * cos(-data->move.rotation));
	}
}
