/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extraction_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:57:12 by gumendes          #+#    #+#             */
/*   Updated: 2026/01/12 16:49:58 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	has_trailing_content(char **info, int start)
{
	int	i;
	int	j;

	i = start;
	while (info[i])
	{
		if (!ft_strcmp(info[i], ""))
		{
			i++;
			continue ;
		}
		j = 0;
		while (info[i][j])
		{
			if (info[i][j] != ' ' && info[i][j] != '\t')
				return (invalid_termination(), 1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_only_blank(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 32 && (line[i] < 9 || line[i] > 13))
			return (0);
		i++;
	}
	return (1);
}

static int	get_map_end(char **info)
{
	int	i;

	i = 0;
	while (info[i] != NULL)
	{
		if (!ft_strcmp(info[i], ""))
			break ;
		else if (is_only_blank(info[i]))
			break ;
		i++;
	}
	if (has_trailing_content(info, i))
		return (-1);
	return (i);
}

int	fill_map(char **info, t_map *map)
{
	int	end;
	int	i;

	if (map->map)
		return (1);
	end = get_map_end(info);
	if (end < 0)
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
