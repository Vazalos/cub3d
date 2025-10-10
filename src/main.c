/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:53:20 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/10 14:30:03 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(void)
{
	t_data	data;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (parse(ac, av, map))
		return (ft_free_map(map), 1);
	ft_init_all(&data, map);
	//mlx_mouse_hide(data.mlx.mlx_ptr, data.mlx.window);
	ft_event_handler(&data);
	mlx_loop_hook(data.mlx.mlx_ptr, render_frame, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return(0);
}
