/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:08:09 by gumendes          #+#    #+#             */
/*   Updated: 2026/01/05 11:15:50 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse(int ac, char **av, t_map *map)
{
	if (ac != 2)
		return (invalid_arg_count(), 1);
	ft_init_map(map);
	if (validate_input(av[1]) != 0)
		return (1);
	if (content_validation(av[1], map) != 0)
		return (1);
	return (0);
}

int	validate_input(char *file)
{
	size_t	i;

	if (ft_strlen(file) < 4
		|| ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4))
		return (invalid_file_type(file), 1);
	i = ft_strlen(file) - 4;
	if (ft_strncmp(file + i, ".cub", 4))
		return (invalid_file_type(file + i), 1);
	return (0);
}

void	set_spawn_point(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (is_spawn_point(map->map[y][x]))
			{
				map->playero = map->map[y][x];
				map->playersx = x + 0.5;
				map->playersy = y + 0.5;
				return ;
			}
		}
	}
}

static int	is_info_all_set(t_map *map)
{
	if (!map->map || !map->no || !map->so || !map->ea || !map->we
		|| map->floor == UINT_MAX || map->ceiling == UINT_MAX
		|| map->playersx == -1 || map->playersy == -1)
	{
		missing_info();
		return (1);
	}
	return (0);
}

int	content_validation(char *file, t_map *map)
{
	int		fd;
	char	*info;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (nonexistant_file(), 1);
	info = extract_information(fd);
	close(fd);
	if (!info)
		return (1);
	if (info_setter(info, map))
		return (free(info), 1);
	free(info);
	set_spawn_point(map);
	if (is_info_all_set(map))
		return (1);
	max_x_setter(map);
	max_y_setter(map);
	map->map[(int)map->playersy][(int)map->playersx] = '0';
	return (0);
}
