/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:33:58 by gumendes          #+#    #+#             */
/*   Updated: 2026/01/13 12:04:27 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	invalid_termination(void)
{
	ft_putstr_fd("Error: Invalid file termination\n", 2);
}

void	invalid_spawn(int type)
{
	if (type < 1)
		ft_putstr_fd("Error: No spawn point found in map\n", 2);
	else
		ft_putstr_fd("Error: Multiple spawn points found in map\n", 2);
}

/**
 * @brief Prints a error message to the STDERR when
 *  the '.ber' file was missing necessary data.
 */
void	missing_info(void)
{
	ft_putstr_fd("Error: Missing or incorrect required", 2);
	ft_putstr_fd(" startup information\n", 2);
}

/**
 * @brief Prints a error message to the STDERR when map is invalid.
 */
void	map_error(void)
{
	ft_putstr_fd("Error: Invalid map\n", 2);
}
