/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extraction_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:57:12 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/22 12:24:19 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_map_end(char **info, int idx)
{
	int	i;
	int	j;

	i = idx;
	while (info[i])
	{
		j = 0;
		while (info[i][j])
		{
			if (!is_map_char(info[i][j]) && info[i][j] != ' ')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	fill_map(char **info, int idx, t_map *map)
{
	int		end;
	int		i;
	int		j;

	if (map->map)
		return (1);
	end = get_map_end(info, idx);
	map->map = malloc(sizeof(char *) * (end - idx + 1));
	if (!map->map)
		return (1);
	i = idx;
	j = 0;
	while (i < end)
	{
		map->map[j] = ft_strdup(info[i]);
		if (!map->map[j])
			return (ft_free_map(map), 1);
		i++;
		j++;
	}
	map->map[j] = NULL;
	return (0);
}

int	is_map_char(int c)
{
	return (c == '0' || c == '1'
		|| c == 'N' || c == 'S'
		|| c == 'E' || c == 'W');
}
