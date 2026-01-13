/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:04:10 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/13 12:18:56 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	ft_bzero(map, sizeof(t_map));
	if (parse(ac, av, map))
		return (ft_free_map(map), 1);
	ft_init_all_bonus(&data, map);
	ft_event_handler(&data);
	mlx_loop_hook(data.mlx.mlx_ptr, render_frame_bonus, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
