/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_extraction_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:24:41 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/22 11:48:54 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	scene_checker(char *values)
{
	char	**tmp;
	size_t	i;

	tmp = ft_split(values, ',');
	i = 0;
	while (tmp[i])
	{
		if (ft_atoi(tmp[i]) < 0 || ft_atoi(tmp[i]) > 255)
		{
			ft_free_split(tmp);
			invalid_rgb_val(tmp[i]);
			return (1);
		}
		i++;
	}
	ft_free_split(tmp);
	return (0);
}

static int	set_f(char *values, t_map *map)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	char			**rgb;

	rgb = ft_split(values, ',');
	r = (unsigned int)ft_atoi(rgb[0]);
	g = (unsigned int)ft_atoi(rgb[1]);
	b = (unsigned int)ft_atoi(rgb[2]);
	ft_free_split(rgb);
	map->floor = ft_argb_to_hex(0xFF, r, g, b);
	return (0);
}

static int	set_c(char *values, t_map *map)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	char			**rgb;

	rgb = ft_split(values, ',');
	r = (unsigned int)ft_atoi(rgb[0]);
	g = (unsigned int)ft_atoi(rgb[1]);
	b = (unsigned int)ft_atoi(rgb[2]);
	ft_free_split(rgb);
	map->ceiling = ft_argb_to_hex(0xFF, r, g, b);
	return (0);
}

int	scene_setter(char *type, char *values, t_map *map)
{
	if (scene_checker(values))
		return (1);
	if (!ft_strcmp(type, "F"))
		return (set_f(values, map));
	if (!ft_strcmp(type, "C"))
		return (set_c(values, map));
	return (0);
}
