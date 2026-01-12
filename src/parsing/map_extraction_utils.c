/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extraction_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:57:12 by gumendes          #+#    #+#             */
/*   Updated: 2026/01/12 14:41:25 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	has_trailing_content(char **info, int end)
{
	int	i;
	int	j;

	i = end;
	while (info[i])
	{
		if (!ft_strcmp(info[i], ""))
			return (1);
		j = 0;
		while (info[i][j])
		{
			if (!is_map_char(info[i][j]))
				return (invalid_termination(), 1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	get_map_end(char **info)
{
	int	i;
	int	j;
	int	has_map_char;

	i = 0;
	while (info[i])
	{
		j = 0;
		has_map_char = 0;
		while (info[i][j])
		{
			if (!is_map_char(info[i][j]))
				return (i);
			if (info[i][j] != ' ')
				has_map_char = 1;
			j++;
		}
		if (!has_map_char)
			return (i);
		i++;
	}
	return (i);
}

int	fill_map(char **info, t_map *map)
{
	int	end;
	int	i;

	if (map->map)
		return (1);
	end = get_map_end(info);
	if (has_trailing_content(info, end))
		return (-1);
	map->map = malloc(sizeof(char *) * (end + 1));
	if (!map->map)
		return (1);
	i = -1;
	while (++i < end)
	{
		map->map[i] = ft_strdup(info[i]);
		if (!map->map[i])
		{
			ft_free_map(map);
			return (1);
		}
	}
	map->map[i] = NULL;
	return (0);
}

int	is_map_char(int c)
{
	return (c == '0' || c == '1'
		|| c == 'N' || c == 'S'
		|| c == 'E' || c == 'W'
		|| c == ' ');
}
