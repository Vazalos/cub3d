/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_extraction_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:05:31 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/18 09:46:02 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	texture_checker(char *path, char *type)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("File path: %s for %s texture missing or permissions denied\n", path, type);
		return (1);
	}
	close(fd);
	return (0);
}

static int	set_no(char *path, t_map *map)
{
	if (!map->no)
	{
		map->no = ft_strdup(path);
		return (0);
	}
	init_error("NO");
	return (1);
}

static int	set_so(char *path, t_map *map)
{
	if (!map->so)
	{
		map->so = ft_strdup(path);
		return (0);
	}
	init_error("SO");
	return (1);
}

static int	set_ea(char *path, t_map *map)
{
	if (!map->ea)
	{
		map->ea = ft_strdup(path);
		return (0);
	}
	init_error("EA");
	return (1);
}

int	texture_setter(char *type, char *path, t_map *map)
{
	if (texture_checker(path, type))
		return (1);
	if (!ft_strcmp(type, "NO"))
		return (set_no(path, map));
	if (!ft_strcmp(type, "SO"))
		return (set_so(path, map));
	if (!ft_strcmp(type, "EA"))
		return (set_ea(path, map));
	if (!ft_strcmp(type, "WE"))
	{
		if (!map->ea)
		{
			map->ea = ft_strdup(path);
			return (0);
		}
		init_error("EA");
		return (1);
	}
	return (1);
}
