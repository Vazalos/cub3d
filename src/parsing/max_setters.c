/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:27:22 by gumendes          #+#    #+#             */
/*   Updated: 2025/10/10 14:19:48 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_max_width(char **map)
{
	int	y;
	int	len;
	int	width;

	y = -1;
	width = 0;
	while (map[++y])
	{
		len = ft_strlen(map[y]);
		if (len > width)
			width = len;
	}
	return (width);
}

/**
 * @brief Sets per collumn height.
 * @param map The struct with all the required data.
 */
void	max_y_setter(t_map *map)
{
	int	y;
	int	x;
	int	height;
	int	width;

	if (!map || !map->map)
		return ;
	width = get_max_width(map->map);
	map->max_y = malloc(sizeof(int) * (width + 1));
	if (!map->max_y)
		return ;
	x = -1;
	while (++x < width)
	{
		height = 0;
		y = -1;
		while (map->map[++y])
			if (map->map[y][x])
				height++;
		map->max_y[x] = height;
	}
	map->max_y[x] = 0;
}

/**
 * @brief Sets per row the width.
 * @param map The struct with all the required data.
 */
void	max_x_setter(t_map *map)
{
	int	y;

	y = get_max_width(map->map);
	map->max_x = malloc(sizeof(int) * (y + 1));
	if (!map->max_x)
		return ;
	y = 0;
	while (map->map[y])
	{
		map->max_x[y] = (int)ft_strlen(map->map[y]);
		y++;
	}
	map->max_x[y] = 0;
}
