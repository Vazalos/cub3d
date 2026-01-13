/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:38:37 by gumendes          #+#    #+#             */
/*   Updated: 2026/01/13 14:21:09 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	map_width(char **map)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	flood_fill(int x, int y, char **map, int w, int h)
{
	if (x < 0 || y < 0 || y >= h || x >= w )
		return (1);
	if ((int)ft_strlen(map[y]) <= x)
		return (1);
	if (map[y][x] == ' ' || map[y][x] == '\0')
		return (1);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (0);
	if (x == 0 || y == 0 || x == w - 1 || y == h - 1)
		return (1);
	map[y][x] = 'F';
	if (flood_fill(x - 1, y, map, w, h))
		return (1);
	if (flood_fill(x + 1, y, map, w, h))
		return (1);
	if (flood_fill(x, y - 1, map, w, h))
		return (1);
	if (flood_fill(x, y + 1, map, w, h))
		return (1);
	return (0);
}
