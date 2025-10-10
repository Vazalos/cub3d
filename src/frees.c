/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:33:16 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/16 15:09:27 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_free_mlx(t_data *data)
{
	if (data->img.img_ptr != NULL)
		mlx_destroy_image(data->mlx.mlx_ptr, data->img.img_ptr);
	if (data->mlx.window != NULL)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.window);
	mlx_destroy_display(data->mlx.mlx_ptr);
	if (data->mlx.mlx_ptr)
		free(data->mlx.mlx_ptr);
	if (data)
		free(data);
	exit(0);
	return (0);
}

	/*
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
	*/