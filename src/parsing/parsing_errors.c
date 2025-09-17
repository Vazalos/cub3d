/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:12:19 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/17 10:28:54 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_error(char *str)
{
	printf("Error: the %s variable is already set\n");
}

void	nonexistant_file(void)
{
	printf("Specified file is nonexistant or the privided path is incorrect\n");
}

void	invalid_file_type(char *str)
{
	printf("Unsupported file extension: %s expected: .cub\n");
}

void	invalid_arg_count(void)
{
	printf("Invalid prompt, try \"./cub3d ./maps/map.cub\"\n");
}
