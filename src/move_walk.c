/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_walk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:05:10 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/16 11:40:28 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	walk(t_data *data)
{
	double	player_radius;
	
	player_radius = 0.15;
	if (data->move.front == 1)
		walk_front(data, player_radius);
	if (data->move.back == 1)
		walk_back(data, player_radius);
	if (data->move.right == 1)
		walk_right(data, player_radius);
	if (data->move.left == 1)
		walk_left(data, player_radius);
}

int	has_collision_x(t_data *data, double x, double rad)
{
	double old_y;

	old_y = data->cast.pov_y;
	if (data->map->map[(int)old_y][(int)(x + rad)] != '0' ||
		data->map->map[(int)old_y][(int)(x - rad)] != '0' ||
		data->map->map[(int)(old_y + rad)][(int)x] != '0' ||
		data->map->map[(int)(old_y - rad)][(int)x] != '0' ||
		data->map->map[(int)(old_y + rad)][(int)(x + rad)] != '0' ||
		data->map->map[(int)(old_y + rad)][(int)(x - rad)] != '0' ||
		data->map->map[(int)(old_y - rad)][(int)(x + rad)] != '0' ||
		data->map->map[(int)(old_y - rad)][(int)(x - rad)] != '0')
		return (1);
	return (0);
}

int	has_collision_y(t_data *data, double y, double rad)
{
	double old_x;

	old_x = data->cast.pov_x;
	if (data->map->map[(int)y][(int)(old_x + rad)] != '0' ||
		data->map->map[(int)y][(int)(old_x - rad)] != '0' ||
		data->map->map[(int)(y + rad)][(int)old_x] != '0' ||
		data->map->map[(int)(y - rad)][(int)old_x] != '0' ||
		data->map->map[(int)(y + rad)][(int)(old_x + rad)] != '0' ||
		data->map->map[(int)(y + rad)][(int)(old_x - rad)] != '0' ||
		data->map->map[(int)(y - rad)][(int)(old_x + rad)] != '0' ||
		data->map->map[(int)(y - rad)][(int)(old_x - rad)] != '0')
		return (1);
	return (0);
}

void	walk_front(t_data *data, double rad)
{
	double	new_y;
	double	new_x;

	new_y = data->cast.pov_y + (data->cast.dir_y * data->move.speed);
	new_x = data->cast.pov_x + (data->cast.dir_x * data->move.speed);
	if (data->map->map[(int)new_y][(int)data->cast.pov_x] == '0'
		&& has_collision_y(data, new_y, rad) == 0)
		data->cast.pov_y = new_y;
	if (data->map->map[(int)data->cast.pov_y][(int)new_x] == '0'
		&& has_collision_x(data, new_x, rad) == 0)
		data->cast.pov_x = new_x;
}

void	walk_back(t_data *data, double rad)
{
	double	new_y;
	double	new_x;

	new_y = data->cast.pov_y - (data->cast.dir_y * data->move.speed);
	new_x = data->cast.pov_x - (data->cast.dir_x * data->move.speed);
	if (data->map->map[(int)new_y][(int)data->cast.pov_x] == '0'
		&& has_collision_y(data, new_y, rad) == 0)
		data->cast.pov_y = new_y;
	if (data->map->map[(int)data->cast.pov_y][(int)new_x] == '0'
		&& has_collision_x(data, new_x, rad) == 0)
		data->cast.pov_x = new_x;
}

void	walk_left(t_data *data, double rad)
{
	double	new_y;
	double	new_x;

	new_y = data->cast.pov_y + (data->cast.dir_x * data->move.speed);
	new_x = data->cast.pov_x - (data->cast.dir_y * data->move.speed);
	if (data->map->map[(int)new_y][(int)data->cast.pov_x] == '0'
		&& has_collision_y(data, new_y, rad) == 0)
		data->cast.pov_y = new_y;
	if (data->map->map[(int)data->cast.pov_y][(int)new_x] == '0'
		&& has_collision_x(data, new_x, rad) == 0)
		data->cast.pov_x = new_x;
}

void	walk_right(t_data *data, double rad)
{
	double	new_y;
	double	new_x;

	new_y = data->cast.pov_y - (data->cast.dir_x * data->move.speed);
	new_x = data->cast.pov_x + (data->cast.dir_y * data->move.speed);
	if (data->map->map[(int)new_y][(int)data->cast.pov_x] == '0'
		&& has_collision_y(data, new_y, rad) == 0)
		data->cast.pov_y = new_y;
	if (data->map->map[(int)data->cast.pov_y][(int)new_x] == '0'
		&& has_collision_x(data, new_x, rad) == 0)
		data->cast.pov_x = new_x;
}
