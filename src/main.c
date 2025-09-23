/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:53:20 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/22 13:50:03 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_init_mlx(data);
	ft_init_values(data);
	ft_init_textures(data);
	ft_event_handler(data);
	mlx_loop_hook(data->mlx.mlx_ptr, render_frame, data);
	mlx_loop(data->mlx.mlx_ptr);
	ft_free_textures(data);
	ft_free_mlx(data);
}
