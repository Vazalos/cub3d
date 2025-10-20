/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:42:51 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/20 16:54:54 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	count_digits(long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

size_t	ft_itoa_cpy(char *const str, const int n)
{
	long		num;
	const int	neg = n < 0;
	int			digits;
	int			i;

	num = n;
	if (neg)
		num = -num;
	digits = count_digits(num);
	str[digits + neg] = '\0';
	if (neg)
		str[0] = '-';
	i = digits + neg;
	while (--i >= neg)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
	}
	return (neg + digits);
}

void	ft_fps_in_window(t_data *data)
{
	static double	prev_print_time;
	static char		to_print[9];
	
	if (has_elapsed_time_interval(prev_print_time, data->time, 0.25) == 1 ||
		prev_print_time == 0)
	{
		prev_print_time = data->time;
		ft_itoa_cpy(to_print, data->fps);
	}
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.window, 10, HEIGHT - 10,
		WHITE, "FPS");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.window, 37, HEIGHT - 10,
		WHITE, to_print);
}

void	print_coords(t_data *data)
{
	printf(
		"\n\n\nPLAYER POS\n	curr map tile %c\n"
		"	pov_x %.2f\n	pov_y %.2f\n"
		"\nVIEW DIRECTION\n	dir_x %.2f\n	dir_y %.2f\n"
		"	plane_x %.2f\n	plane_y %.2f\n\n"
		"	mouse_y %.2f\n	mouse_x %.2f\n"
		"	map_x %i\n	map_y %i\n"
		"\nDISTANCE CALCS\n	sidedist_x %.2f\n	sidedist_y %.2f\n"
		"	deltadist_x %.2f\n	deltadist_y %.2f\n"
		"	perpend_wall_dist %.2f\n	step_x %i\n	step_y %i\n"
		"\nWALLS\n	hit (wall)%i\n	side %i\n"
		"	wall_height %i\n	wall_start_y %i\n	wall_end_y %i\n\n\n",
		data->map->map[(int)data->cast.pov_y][(int)data->cast.pov_x],
		data->cast.pov_x, data->cast.pov_y,
		data->cast.dir_x, data->cast.dir_y,
		data->cast.plane_x, data->cast.plane_y,
		data->mouse.y, data->mouse.x,
		data->cast.map_x, data->cast.map_y,
		data->cast.side_dist_x, data->cast.side_dist_y,
		data->cast.delta_dist_x, data->cast.delta_dist_y,
		data->cast.perpend_wall_dist, data->cast.step_x, data->cast.step_y,
		data->cast.wall_hit, data->cast.side,
		data->cast.line_height, data->cast.draw_start, data->cast.draw_end);
}

void	print_extra_coords(t_data *data)
{
	printf(
		"old_mouse_x %.2f\n"
		"mousex - oldmousex = %.2f\n"
		"ray_dir_x %.2f\nray_dir_y %.2f\n"
		"camera_x %.2f\n"
		"color %X OR %u\n\n"
		,
		data->cast.camera_x,
		data->mouse.old_x,
		data->mouse.old_x - data->mouse.x,
		data->cast.ray_dir_x, data->cast.ray_dir_y,
		data->cast.wall_color, data->cast.wall_color
	);
}