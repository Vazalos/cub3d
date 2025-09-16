/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_extraction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:41:26 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/16 15:47:36 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_texture(char *line, t_map *map)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (!ft_strcmp(tmp[0], "NO"))
		if (!map->no)
			map->no = ft_strdup(tmp[1]);
		else
			return (init_error("NO"), 1);
	if (!ft_strcmp(tmp[0], "SO"))
		if (!map->so)
			map->so = ft_strdup(tmp[1]);
		else
			return (init_error("SO"), 1);
	if (!ft_strcmp(tmp[0], "EA"))
		if (!map->ea)
			map->ea = ft_strdup(tmp[1]);
		else
			return (init_error("EA"), 1);
	if (!ft_strcmp(tmp[0], "WE"))
		if (!map->we)
			map->we = ft_strdup(tmp[1]);
		else
			return (init_error("WE"), 1);
	ft_free_split(tmp);
	return (0);
}

int	is_f_c(char *line, t_map *map)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (ft_strcmp(tmp[0], "F") == 0)
}

int	extract_information(int fd, t_map *map)
{
	char	*line;
	char	*file;
	char	*tmp;

	line = gnl(fd);
	while (line)
	{
		if (!file)
			file = ft_strdup(line);
		else
		{
			tmp = file;
			file = ft_strjoin(tmp, line);
			free(tmp);
		}
		free(line);
		line = gnl(fd);
	}
}
