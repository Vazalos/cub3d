/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_extraction_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:05:31 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/17 10:58:28 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	texture_checker(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("File for %s texture missing or permissions denied\n", type);
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

int	texture_setter(char *line, t_map *map)
{
	char	**info;

	info = ft_split(line, ' ');
	if (texture_checker(info[1]))
		return (1);
	if (!ft_strcmp(info[0], "NO"))
		return (ft_free_split(info), set_no(info[1], map));
	if (!ft_strcmp(info[0], "SO"))
		return (ft_free_split(info), set_so(info[1], map));
	if (!ft_strcmp(info[0], "EA"))
		return (ft_free_split(info), set_ea(info[1], map));
	if (!ft_strcmp(info[0], "WE"))
	{
		if (!map->ea)
		{
			map->ea = ft_strdup(path);
			return (ft_free_split(info), 0);
		}
		ft_free_split(info);
		init_error("EA");
		return (1);
	}
	ft_free_split(info);
	return (1);
}
