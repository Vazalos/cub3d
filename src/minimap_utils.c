/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:57:47 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/16 13:33:58 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
 
unsigned int get_alpha_color(t_data *data, int target_x, int target_y,
	unsigned int new_color)
{
	unsigned int target_color;
	unsigned int color_mix;
	
	target_color = (*(unsigned int *)((data->img.pix_addr + target_y
		* data->img.line_len) + (target_x * (data->img.bpp / 8))));
	color_mix = (
    (((target_color >> 16 & 0xFF) + (new_color >> 16 & 0xFF)) / 2) << 16 |
    (((target_color >> 8  & 0xFF) + (new_color >> 8  & 0xFF)) / 2) << 8  |
    (((target_color       & 0xFF) + (new_color       & 0xFF)) / 2));

	return (color_mix);
}
