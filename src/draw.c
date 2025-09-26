/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:32:46 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/25 16:48:01 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel_dest;

	pixel_dest = data->img.pix_addr + ((y * data->img.line_len)
			+ (x * (data->img.bpp / 8)));
	*(unsigned int *)pixel_dest = color;
}

void	ft_draw_vertical_line(t_data *data, int x)
{
	int	y;
	int	horizon;

	horizon = HEIGHT / 2;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < data->calc.draw_start && y <= horizon)
			ft_draw_pixel(data, x, y, SKY);
		else if (y >= data->calc.draw_start && y <= data->calc.draw_end)
			ft_draw_pixel(data, x, y, data->calc.wall_color);
		else if (y > data->calc.draw_end && y > horizon)
			ft_draw_pixel(data, x, y, FLOOR);
		ft_draw_crosshair(data, x, y);
		y++;
	}
}

void	ft_draw_crosshair(t_data *data, int x, int y)
{
	if ((x >= WIDTH / 2 - 2 && x <= WIDTH / 2 + 2) && y == HEIGHT / 2)
		ft_draw_pixel(data, x, y, WHITE);
	if (x == WIDTH / 2 && (y >= HEIGHT / 2 - 2 && y <= HEIGHT / 2 + 2))
		ft_draw_pixel(data, x, y, WHITE);
}

void	ft_draw_background(t_data *data)
{
	int	x;
	int	y;
	int	horizon;

	x = 0;
	y = 0;
	horizon = HEIGHT / 2;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			if (y < horizon)
				ft_draw_pixel(data, x, y, SKY);
			else
				ft_draw_pixel(data, x, y, FLOOR);
			y++;
		}
		x++;
		y = 0;
	}
}
