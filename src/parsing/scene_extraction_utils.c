/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_extraction_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:24:41 by gumendes          #+#    #+#             */
/*   Updated: 2026/01/13 12:04:57 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_valid_scene(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
		i++;
	if (i > 3)
		return (0);
	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (ft_isalpha(rgb[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	scene_checker(char *values)
{
	char	**tmp;
	size_t	i;

	tmp = ft_split(values, ',');
	if (!is_valid_scene(tmp))
		return (ft_free_split(tmp), 1);
	i = 0;
	while (tmp[i])
	{
		if (ft_atoi(tmp[i]) < 0 || ft_atoi(tmp[i]) > 255)
		{
			ft_free_split(tmp);
			return (1);
		}
		i++;
	}
	ft_free_split(tmp);
	return (0);
}

static int	set_rgb(char *values, unsigned int *dest)
{
	char			**rgb;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	rgb = ft_split(values, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (ft_free_split(rgb), 1);
	r = (unsigned int)ft_atoi(rgb[0]);
	g = (unsigned int)ft_atoi(rgb[1]);
	b = (unsigned int)ft_atoi(rgb[2]);
	ft_free_split(rgb);
	*dest = ft_argb_to_hex(0x00, r, g, b);
	return (0);
}

int	scene_setter(char *type, char *values, t_map *map)
{
	if (scene_checker(values))
		return (1);
	if (!ft_strcmp(type, "F"))
		return (set_rgb(values, &map->floor));
	if (!ft_strcmp(type, "C"))
		return (set_rgb(values, &map->ceiling));
	return (0);
}
