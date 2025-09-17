/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_setters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:46:36 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/17 10:58:04 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	info_setter(char *info, t_map map)
{
	char	**tmp;
	size_t	i;

	tmp = ft_split(info, '\n');
	while (tmp[i])
	{
		if (!is_texture(tmp[i]))
			
	}
	
}
