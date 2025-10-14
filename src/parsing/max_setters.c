/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:27:22 by gumendes          #+#    #+#             */
/*   Updated: 2025/10/14 16:18:44 by david-fe         ###   ########.fr       */
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
	int	max_height;

	width = get_max_width(map->map);
	max_height = 0;
	// map->max_y = malloc(sizeof(int) * (width + 1));
	// if (!map->max_y)
	// 	return ;
	x = -1;
	while (++x < width)
	 {
        height = 0;
        y = 0;
        while (map->map[y])
        {
            // Check if row y has a character at column x and it's not null terminator
            if (map->map[y][x] != '\0')
                height++;
            y++;
        }
        if (height > max_height)
            max_height = height;
    }
	map->max_y = max_height;
}

// void	max_y_setter(t_map *map)
// {
// 	int	y;
// 	int	x;
// 	int	height;
// 	int	width;

// 	if (!map || !map->map)
// 		return ;
// 	width = get_max_width(map->map);
// 	map->max_y = malloc(sizeof(int) * (width + 1));
// 	if (!map->max_y)
// 		return ;
// 	x = -1;
// 	while (++x < width)
// 	{
// 		height = 0;
// 		y = -1;
// 		while (map->map[++y])
// 			if (map->map[y][x])
// 				height++;
// 		map->max_y[x] = height;
// 	}
// 	map->max_y[x] = 0;
// }

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
