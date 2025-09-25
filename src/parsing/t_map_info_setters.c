/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_info_setters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:46:36 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/25 13:05:18 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	info_setter(char *info, t_map *map)
{
	char	**tmp;
	int		i;

	tmp = ft_split(info, '\n');
	i = 0;
	while (tmp[i])
	{
		if (!is_texture(tmp[i], map)) {
			i++;
   			continue ;
		}
		else if (!is_scene(tmp[i], map)) {
			i++;
   			continue ;
		}
		else if (!is_map(tmp + i, map))
		{
    		if (check_map(map))
				return (ft_free_split(tmp), 1);
			return (ft_free_split(tmp), 0);
		}
		else
			return (ft_free_split(tmp), 1);
	}
	return (ft_free_split(tmp), 0);
}
