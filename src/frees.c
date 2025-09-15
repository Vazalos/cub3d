/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:33:16 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/15 16:30:38 by david-fe         ###   ########.fr       */
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
