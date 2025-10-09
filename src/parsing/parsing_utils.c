/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:15:23 by gumendes          #+#    #+#             */
/*   Updated: 2025/10/09 16:04:03 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	max_x_setter(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
		i++;
	map->max_x = malloc(sizeof(int) * i + 1);
	if (!map->max_x)
		return ;
	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		map->max_x[i] = j;
		i++;
	}
	map->max_x[i] = 0;
}

/**
 * @brief Checks wether or not a given character is a player spawn point('N', 'S', 'E', 'W').
 * @param to_check The tile to verify.
 * @return 1 if specified tile is a player spwan point.
 *
 * 0 if specified tile is not a player spwan point.
 */
int	is_spawn_point(char to_check)
{
	if (to_check == 'N'
		|| to_check == 'S'
		|| to_check == 'E'
		|| to_check == 'W')
		return (1);
	return (0);
}

/**
 * @brief Initializes all the values of the map struct.
 * @param map The struct being innitialized.
 */
void	ft_init_map(t_map *map)
{
	map->ceiling = UINT_MAX;
	map->floor = UINT_MAX;
	map->playersx = -1;
	map->playersy = -1;
	map->ea = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->map = NULL;
}

/**
 * @brief Compares two strings character by character.
 *
 * The comparison stops at the first differing character or at the end of either string.
 *
 * @param s1 The first null-terminated string.
 * @param s2 The second null-terminated string.
 * @return The difference between the ASCII values of the first differing characters.
 * Returns 0 if both strings are equal.
 */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
