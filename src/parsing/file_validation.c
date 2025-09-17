/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:08:09 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/17 10:49:04 by gumendes         ###   ########.fr       */
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
}

int	validate_input(char *file)
{
	size_t	i;

	i = ft_strlen(file) - 4;
	if (ft_strncmp(file + i, ".cub", 4))
		return (invalid_file_type(file + i), 1);
	return (0);
}

int	content_validation(char *file, t_map *map)
{
	int		fd;
	char	*info;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (nonexistant_file(), 1);
	info = extract_information(fd, map);
	if (!info)
		return (1);
	if (info_setter(info, map))
		return (1);
	return (0);
}
