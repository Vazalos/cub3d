/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:07:52 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/12 14:34:22 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render_frame_bonus(t_data *data)
{
	ft_draw_background(data);
	ft_raycast_bonus(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.window,
		data->img.img_ptr, 0, 0);
	ft_fps_in_window(data);
	return (0);
}

void	ft_raycast_bonus(t_data *data)
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

void	ft_init_all_bonus(t_data *data, t_map *map)
{
	ft_bzero(data, sizeof(t_data));
	data->map = map;
	ft_init_mlx(data);
	ft_init_values(data);
	ft_init_textures(data, map);
	init_minimap(data);
}

void	rotate_with_mouse(t_data *data)
{
	double	mouse_ratio;
	double	mouse_delta;

	mouse_delta = data->mouse.pos.x - data->mouse.old_x;
	mouse_ratio = (-data->mouse.offset_x / (WIDTH / 2))
		* DELTA_MULT - (mouse_delta / (WIDTH * 4));
	rotation_calcs(data, mouse_ratio);
	mlx_mouse_move(data->mlx.mlx_ptr, data->mlx.window, WIDTH / 2, HEIGHT / 2);
}
