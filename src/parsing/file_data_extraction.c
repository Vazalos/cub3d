/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_extraction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:41:26 by gumendes          #+#    #+#             */
/*   Updated: 2025/10/09 14:33:22 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_map_char_only(char *line)
{
	int i;
	int found;

	i = 0;
	found = 0;
	if (!line || !*line)
		return (0);
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' ||
			line[i] == 'N' || line[i] == 'S' ||
			line[i] == 'E' || line[i] == 'W' ||
			line[i] == ' ')
			found = 1;
		else
			return (0);
		i++;
	}
	return (found);
}

int	is_map(char **info, t_map *map)
{
	int	i;

	i = 0;
	if (!info || !info[i])
		return (0);
	while (info[i])
	{
		if (is_map_char_only(info[i]))
			return (fill_map(info + i, map));
		i++;
	}
	return (1);
}

int	is_scene(char *line, t_map *map)
{
	char	**tmp;
	int		ret;

	if (!line || !*line)
		return (0);
	tmp = ft_split(line, ' ');
	if (!tmp || !tmp[0])
		return (ft_free_split(tmp), 0);
	ret = 1;
	if (!ft_strncmp(tmp[0], "F", 1))
		ret = scene_setter("F", tmp[1], map);
	else if (!ft_strncmp(tmp[0], "C", 1))
		ret = scene_setter("C", tmp[1], map);
	ft_free_split(tmp);
	return (ret);
}

int	is_texture(char *line, t_map *map)
{
	char	**tmp;
	int		ret;

	if (!line || !*line)
		return (0);
	tmp = ft_split(line, ' ');
	if (!tmp || !tmp[0])
		return (ft_free_split(tmp), 0);
	ret = 1;
	if (!ft_strcmp(tmp[0], "NO"))
		ret = texture_setter("NO", tmp[1], map);
	else if (!ft_strcmp(tmp[0], "SO"))
		ret = texture_setter("SO", tmp[1], map);
	else if (!ft_strcmp(tmp[0], "EA"))
		ret = texture_setter("EA", tmp[1], map);
	else if (!ft_strcmp(tmp[0], "WE"))
		ret = texture_setter("WE", tmp[1], map);
	ft_free_split(tmp);
	return (ret);
}

char	*extract_information(int fd)
{
	char	*line;
	char	*file;
	char	*tmp;

	file = NULL;
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
		if (!file)
			return (NULL);
		line = gnl(fd);
	}
	return (file);
}
