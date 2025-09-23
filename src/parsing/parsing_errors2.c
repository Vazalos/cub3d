/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:33:58 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/23 14:52:16 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Prints a error message to the STDERR when
 *  the '.ber' file was missing necessary data.
 */
void	missing_info(void)
{
	write(2, "Error: missing required startup information\n", 44);
}

/**
 * @brief Prints a error message to the STDERR when map is invalid.
 */
void	map_error(void)
{
	write(2, "Error: Invalid map\n", 19);
}
