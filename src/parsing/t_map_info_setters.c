/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_info_setters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:46:36 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/22 12:27:04 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	info_setter(char *info, t_map *map)
{
	char	**tmp;
	int		i;

	tmp = ft_split(info, '\n');
	i = -1;
	while (tmp[++i])
	{
		if (!is_texture(tmp[i], map))
			continue ;
		if (!is_scene(tmp[i], map))
			continue ;
		if (!is_map(tmp, i, map))
		{
			if (!check_map(map))
				return (0);
			ft_free_map(map);
			return (0);
			// check map
			// if invalid return and end execution
			// if valid end execution as map is always last, if anything is not filled file is invalid
		}
	}
	return (0);
}
