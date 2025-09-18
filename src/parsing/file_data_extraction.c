/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_extraction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:41:26 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/18 09:46:46 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_scene(char *line, t_map *map)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (!ft_strcmp(tmp[0], "F"))
		return (scene_setter("F", tmp[1], map));
	if (!ft_strcmp(tmp[0], "C"))
		return (scene_setter("C", tmp[1], map));
}

int	is_texture(char *line, t_map *map)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (!ft_strcmp(tmp[0], "NO"))
		return (texture_setter("NO", tmp[1], map));
	if (!ft_strcmp(tmp[0], "SO"))
		return (texture_setter("SO", tmp[1], map));
	if (!ft_strcmp(tmp[0], "EA"))
		return (texture_setter("EA", tmp[1], map));
	if (!ft_strcmp(tmp[0], "WE"))
		return (texture_setter("WE", tmp[1], map));
	ft_free_split(tmp);
	return (0);
}

char	*extract_information(int fd, t_map *map)
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
	free(line);
	return (file);
}
