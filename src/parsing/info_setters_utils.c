/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_setters_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumendes <gumendes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 10:51:44 by gumendes          #+#    #+#             */
/*   Updated: 2025/09/17 10:53:50 by gumendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_texture(char *to_check)
{
	if (!ft_strncmp(to_check, "NO", 2))
		return (0);
	if (!ft_strncmp(to_check, "SO", 2))
		return (0);
	if (!ft_strncmp(to_check, "EA", 2))
		return (0);
	if (!ft_strncmp(to_check, "WE", 2))
		return (0);
	return (1);
}
