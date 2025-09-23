/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:12:19 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/23 14:42:36 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Prints a error message to the STDERR when the
 *  given rgb value of the floor/ceiling is invalid.
 */
void	invalid_rgb_val(char *value)
{
	write(2, "Error: The provided value: ", 27);
	write(2, value, ft_strlen(value));
	write(2, " is outside of the conventional rgb range (0-255)\n", 50);
}

/**
 * @brief Prints a error message to the STDERR when trying to define
 *  an already set variable.
 */
void	init_error(char *str)
{
	write(2, "Error: the ", 11);
	write(2, str, ft_strlen(str));
	write(2, " variable is already set\n", 25);
}

/**
 * @brief Prints a error message to the STDERR when the '.ber'
 *  file is non-existant, missing permissions or the path is incorrect.
 */
void	nonexistant_file(void)
{
	write(2, "Specified file is non-existant or", 33);
	write(2, " the provided path is incorrect", 31);
	write(2, " or insufficient permissions\n", 29);
}

/**
 * @brief Prints a error message to the STDERR when
 *  the file is not of the '.ber' type.
 */
void	invalid_file_type(char *str)
{
	write(2, "Error: Unsupported file extension: ", 35);
	write(2, str, ft_strlen(str));
	write(2, " expected: .cub\n", 16);
}

/**
 * @brief Prints a error message to the STDERR when the argc values is different from 2.
 */
void	invalid_arg_count(void)
{
	write(2, "Invalid prompt, try \"./cub3d ./maps/map.cub\"\n", 44);
}
