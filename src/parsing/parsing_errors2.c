/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:33:58 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/25 11:02:21 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Prints a error message to the STDERR when
 *  the '.ber' file was missing necessary data.
 */
void	missing_info(void)
{
	ft_putstr_fd("Error: missing required startup information\n", 2);
}

/**
 * @brief Prints a error message to the STDERR when map is invalid.
 */
void	map_error(void)
{
	ft_putstr_fd("Error: Invalid map\n", 2);
}
