/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:53:20 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/16 11:09:30 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render_frame(t_data *data)
{
	ft_draw_background(data);
	ft_raycast(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.window,
		data->img.img_ptr, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_init_mlx(data);
	ft_init_values(data);
	ft_event_handler(data);
	mlx_loop_hook(data->mlx.mlx_ptr, render_frame, data);
	mlx_loop(data->mlx.mlx_ptr);
	ft_free_mlx(data);
}

double	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (0);
	return ((double)((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}
