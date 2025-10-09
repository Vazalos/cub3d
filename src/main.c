/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:53:20 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/09 14:32:15 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;

	map = malloc(sizeof(t_map));
	parse(ac, av, map);
	ft_init_all(&data, map);
	//mlx_mouse_hide(data.mlx.mlx_ptr, data.mlx.window);
	ft_event_handler(&data);
	mlx_loop_hook(data.mlx.mlx_ptr, render_frame, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return(0);
}
