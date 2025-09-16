/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:08:09 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/16 11:20:06 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse(int ac, char **av)
{
	if (ac != 2)
		return (invalid_arg_count(), 1);
	if (validate_input(av[1]) != 0)
		return (1);
}

int	validate_input(char *file)
