/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:39:46 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/17 17:08:26 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_base_coords(t_data *data, int x);
void	frame_time_and_speed(t_data *data);

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
		if ((x >= WIDTH/2 - 2 && x <= WIDTH/2 + 2) && y == HEIGHT/2)
			ft_draw_pixel(data, x, y, WHITE);
		if (x == WIDTH/2 && (y >= HEIGHT/2 - 2 && y <= HEIGHT/2 + 2))
			ft_draw_pixel(data, x, y, WHITE);
		y++;
	}
}

void	get_base_coords(t_data *data, int x)
{
		data->calc.camera_x = 2 * x / (double)WIDTH - 1;
		data->calc.ray_dir_x = data->calc.dir_x
			+ data->calc.plane_x * data->calc.camera_x;
		data->calc.ray_dir_y = data->calc.dir_y
			+ data->calc.plane_y * data->calc.camera_x;
		data->calc.map_x = (int)data->calc.pov_x;
		data->calc.map_y = (int)data->calc.pov_y;	
}

void	frame_time_and_speed(t_data *data)
{
	data->old_time = data->time;
	data->time = ft_get_time();
	data->frame_time = (data->time - data->old_time) / 1000.0;
	//print_fps(data->frame_time);
	data->move.speed = data->frame_time * 5.0; 
	data->move.rotation = data->frame_time * 3.0;
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

	x = -1;
	while (++x < WIDTH)
	{
		get_base_coords(data, x);
		dist_per_square_x(data);
		dist_per_square_y(data);
		wall_hit_dist(data, map);
		wall_height_and_color(data, map);
		ft_draw_vertical(data, x);
		//if (x == WIDTH/2)
		//	print_coords(data);
	}
	frame_time_and_speed(data);
	walk(data, map);
	rotate(data);
}
