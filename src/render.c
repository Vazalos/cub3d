/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:59:07 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/01 15:55:41 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render_frame(t_data *data)
{
	ft_draw_background(data);
	ft_raycast(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.window,
		data->img.img_ptr, 0, 0);
	//mlx_string_put(data->mlx.mlx_ptr, data->mlx.window, 10, HEIGHT - 10,
	//	WHITE, ft_itoa(data->fps));
	return (0);
}

double	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (0);
	return ((double)((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}


