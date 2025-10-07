/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extraction_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:57:12 by gumendes          #+#    #+#             */
/*   Updated: 2025/10/07 18:02:31 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_map_end(char **info)
{
    int	i;
    int	j;
    int	has_map_char;

    i = 0;
    while (info[i])
    {
        j = 0;
        has_map_char = 0;
        while (info[i][j])
        {
            if (!is_map_char(info[i][j]))
                return (printf("stoping at: %s\n" ,info [i]), i);
            if (info[i][j] != ' ')
                has_map_char = 1;
            j++;
        }
        if (!has_map_char)
            return (i);
        i++;
    }
    return (i);
}

int	fill_map(char **info, t_map *map)
{
	int	end;
	int	i;
	int	j;

	if (map->map)
		return (1);
	end = get_map_end(info);
	map->map = malloc(sizeof(char *) * (end + 1));
	if (!map->map)
		return (1);
	i = -1;
	j = 0;
	while (++i < end)
	{
		map->map[j] = ft_strdup(info[i]);;
		if (!map->map[j])
		{
			ft_free_map(map);
			map->map = NULL;
			return (1);
		}
		j++;
	}
	map->map[j] = NULL;
	return (0);
}

int	is_map_char(int c)
{
	return (c == '0' || c == '1'
		|| c == 'N' || c == 'S'
		|| c == 'E' || c == 'W'
		|| c == ' ');
}
