/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_info_setters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:46:36 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/26 12:20:31 by gumendes         ###   ########.fr       */
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
		if (!is_texture(tmp[i], map)) {
			printf("tex\n");
			continue ;
		}
		else if (!is_scene(tmp[i], map)){
			printf("scene\n");
			continue ;
		}
		if (!is_map(tmp + i, map))
		{
			printf("map %d\n", i);
			if (check_map(map))
				return (ft_free_split(tmp), 1);
			return (ft_free_split(tmp), 0);
		}
	}
	printf("\n\n\n%d\n\n\n", i);
	return (ft_free_split(tmp), 0);
}
