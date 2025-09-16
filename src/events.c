/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:32:42 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/16 10:52:53 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_event_handler(t_data *data)
{
	mlx_hook(data->mlx.window, DestroyNotify, 0, ft_free_mlx, data);
	mlx_hook(data->mlx.window, KeyPress, KeyPressMask, ft_keypress, data);
	mlx_hook(data->mlx.window, 6, 1L << 6, ft_mouse_move, data);
}

int	ft_mouse_move(int x, int y, t_data *data)
{
	data->calc.mouse_x = x;
	data->calc.mouse_y = y;
	return (0);
}

int	ft_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_free_mlx(data);
	if (keysym == XK_Left || keysym == XK_Right)
	{
		//look to sides
	}
	if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d)
	{
		//move
	}
	return (0);
}
