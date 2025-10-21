/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:19:19 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/21 14:35:59 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	has_collision_x(t_data *data, double x, double rad)
{
	double	old_y;

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
	double	old_x;

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
