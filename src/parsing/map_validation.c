/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:27:29 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/22 14:43:52 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_start(char *start)
{
	int	i;

	i = 0;
	while (start[i])
	{
		if (start[i] != ' ' && start[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_invalid_char(const char **map)
{
	size_t	i;
	size_t	j;
	size_t	flag;

	i = 0;
	flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W')
				return (1);
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		return (1);
	return (0);
}

static int	wall_start(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			return (i);
		i++;
	}
	return (-1);
}

static int	wall_end(const char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i > 0)
	{
		if (line[i] == '1')
			return (i);
		i--;
	}
}

static int	bad_bounds(const char **map)
{
	int	i;
	int	end;
	int	inside;

	i = 0;
	if (check_start(map[0]))
		return (1);
	end = 0;
	while (map[end])
		end++;
	if (check_start(map[end - 1]))
		return (1);
	while (i < end)
	{
		if (wall_start(map[i]) == wall_end(map[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_map(t_map *map)
{
	if (check_invalid_char(map->map))
		return (1);
	if (bad_bounds(map->map))
		return (1);
	if (bad_interiors(map->map))
}
