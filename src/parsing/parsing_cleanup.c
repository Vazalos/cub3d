/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cleanup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:56:10 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/16 15:39:43 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_map(t_map *map)
{
	size_t	i;

	if (map->ea)
		free(map->ea);
	if (map->we)
		free(map->we);
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->map)
	{
		i = 0;
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}
