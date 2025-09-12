/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:32:46 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/11 13:25:17 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_draw_pixel(t_data *data, int x, int y, int color)
{
    char    *pixel_dest;

    pixel_dest = data->img.pix_addr + 
        ((y * data->img.line_len) + (x * (data->img.bpp / 8)));
    *(unsigned int *)pixel_dest = color;
}

void    ft_draw_background(t_data *data)
{
    int x = 0;
    int y = 0;
    int horizon = HEIGHT / 2;

    while (x < WIDTH)
    {
        while (y < HEIGHT)
        {
            if(y < horizon)
                ft_draw_pixel(data, x, y, SKY);
            else
                ft_draw_pixel(data, x, y, FLOOR);
            y++;
        }
        x++;
        y = 0;
    }
}