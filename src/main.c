/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:53:20 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/12 13:23:27 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int render_frame(t_data *data)
{
    ft_draw_background(data);
    ft_raycast(data);
    return (0);
}

int main(void)
{
    t_data *data;
    
    data = malloc(sizeof(t_data));
    if(!data)
        return(1);
    ft_init_mlx(data);
    ft_event_handler(data);
    ft_draw_background(data);
    mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.window, data->img.img_ptr, 0, 0);
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

void ft_init_values(t_data *data)
{
    data->view.pov_x = 22;
    data->view.pov_y = 12;
    data->view.dir_x = -1;
    data->view.dir_y = 0;
    data->view.plane_x = 0;
    data->view.plane_y = 0.66;
    
    data->start_time = ft_get_time();
    data->time = data->start_time;
    data->old_time = data->start_time;
}