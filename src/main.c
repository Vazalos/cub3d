/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:53:20 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/26 10:55:43 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	parse(ac, av, map);
	printf("---Testing---\n");
	printf("\n---Wall Textures---\n");
	printf("NO: %s\nSO: %s\nWE: %s\nEA: %s\n", map->no, map->so, map->we, map->ea);
	printf("\n---Ceiling and Floor---\n");
	printf("Ceilinlg: %x\nFloor: %x\n", map->floor, map->ceiling);
	printf("\n---Map---\n");
	int i = 0;
	while (map->map[i]) {
		printf("%s\n", map->map[i]);
		i++;
	}
	printf("\n\nPlayer Spawn\nX: %f\nY: %f\nO: %c\n", map->playersx, map->playersy, map->playero);
	printf("---------------------------------------------\n");
	ft_free_map(map);
}

/* int	main(int ac, char **av)
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
} */
