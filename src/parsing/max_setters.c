/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:27:22 by gumendes          #+#    #+#             */
/*   Updated: 2026/01/12 13:22:06 by gumendes         ###   ########.fr       */
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
 * @brief Sets per column height.
 * @param map The struct with all the required data.
 */
void	max_y_setter(t_map *map)
{
	int	x;
	int	y;
	int	len;
	int	max_height;

	x = 0;
	max_height = 0;
	while (x < get_max_width(map->map))
	{
		y = 0;
		while (map->map[y])
		{
			len = ft_strlen(map->map[y]);
			if (x < len)
			{
				if (y + 1 > max_height)
					max_height = y + 1;
			}
			y++;
		}
		x++;
	}
	map->max_y = max_height;
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
