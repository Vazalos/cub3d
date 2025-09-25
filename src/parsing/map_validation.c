/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:27:29 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/25 12:08:03 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_invalid_char(char **map)
{
	size_t	i;
	size_t	j;
	int		spawn_count;

	i = 0;
	spawn_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != '1'
				&& !is_spawn_point(map[i][j]))
			{
				printf("Invalid character '%c' at row %zu, col %zu\n",
					map[i][j], i, j);
				return (1);
			}
			if (is_spawn_point(map[i][j]))
				spawn_count++;
			j++;
		}
		i++;
	}
	if (spawn_count == 0)
	{
		printf("Error: No spawn point found in map\n");
		return (1);
	}
	if (spawn_count > 1)
	{
		printf("Error: Multiple spawn points found in map (%d)\n", spawn_count);
		return (1);
	}
	return (0);
}

static int	flood_fill(int x, int y, char **map)
{
	if (y < 0 || !map[y] || x < 0 || x >= (int)ft_strlen(map[y])
		|| map[y][x] == ' ')
		return (1);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (0);
	map[y][x] = 'F';
	if (flood_fill(x - 1, y, map))
		return (1);
	if (flood_fill(x + 1, y, map))
		return (1);
	if (flood_fill(x, y - 1, map))
		return (1);
	if (flood_fill(x, y + 1, map))
		return (1);
	return (0);
}

static char	**map_duper(char **map)
{
	int		i;
	char	**dup_map;

	i = 0;
	while (map[i])
		i++;
	dup_map = malloc(sizeof(char *) * (i + 1));
	if (!dup_map)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		dup_map[i] = ft_strdup(map[i]);
		if (!dup_map[i])
		{
			while (i > 0)
				free(dup_map[--i]);
			free(dup_map);
			return (NULL);
		}
	}
	dup_map[i] = NULL;
	return (dup_map);
}

static int	invalid_map(char **map)
{
	int		x;
	int		y;
	int		found;
	char	**dup_map;

	y = -1;
	x = -1;
	found = 0;
	while (map[++y] && !found)
	{
		x = -1;
		while (map[y][++x])
		{
			if (is_spawn_point(map[y][x]))
			{
				found = 1;
				break ;
			}
		}
	}
	dup_map = map_duper(map);
	if (flood_fill(x, y, dup_map))
		return (ft_free_split(dup_map), 1);
	return (ft_free_split(dup_map), 0);
}

int	check_map(t_map *map)
{
	if (check_invalid_char(map->map))
		return (map_error(), 1);
	if (invalid_map(map->map))
		return (map_error(), 1);
	return (0);
}
