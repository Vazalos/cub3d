/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:12:19 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/25 11:05:15 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Prints a error message to the STDERR when the
 *  given rgb value of the floor/ceiling is invalid.
 */
void	invalid_rgb_val(char *value)
{
	ft_putstr_fd("Error: The provided value: ", 2);
	ft_putstr_fd(value, 2);
	ft_putstr_fd(" is outside of the conventional rgb range (0-255)\n", 2);
}

/**
 * @brief Prints a error message to the STDERR when trying to define
 *  an already set variable.
 */
void	init_error(char *str)
{
	ft_putstr_fd("Error: the ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" variable is already set\n", 2);
}

/**
 * @brief Prints a error message to the STDERR when the '.ber'
 *  file is non-existant, missing permissions or the path is incorrect.
 */
void	nonexistant_file(void)
{
	ft_putstr_fd("Specified file is non-existant or", 2);
	ft_putstr_fd(" the provided path is incorrect", 2);
	ft_putstr_fd(" or insufficient permissions\n", 2);
}

/**
 * @brief Prints a error message to the STDERR when
 *  the file is not of the '.ber' type.
 */
void	invalid_file_type(char *str)
{
	ft_putstr_fd("Error: Unsupported file extension: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" expected: .cub\n", 2);
}

/**
 * @brief Prints a error message to the STDERR when the argc values is different from 2.
 */
void	invalid_arg_count(void)
{
	ft_putstr_fd("Invalid prompt, try \"./cub3d ./maps/map.cub\"\n", 2);
}
