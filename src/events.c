/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:32:42 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/14 14:08:56 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_event_handler(t_data *data)
{
	mlx_hook(data->mlx.window, DestroyNotify, 0, ft_free_mlx, data);
	mlx_hook(data->mlx.window, KeyPress, KeyPressMask, ft_key_press, data);
	mlx_hook(data->mlx.window, KeyRelease, KeyReleaseMask, ft_key_release,
		data);
	mlx_hook(data->mlx.window, 6, 1L << 6, ft_mouse_move, data);
}

int	ft_mouse_move(int x, int y, t_data *data)
{
	data->mouse.old_x = data->mouse.x;
	data->mouse.y = y;
	data->mouse.x = x;
	data->mouse.offset_x = (data->mouse.x - (WIDTH / 2));
	return (0);
}

int	ft_key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_free_mlx(data);
	if (keysym == XK_w || keysym == XK_Up)
		data->move.front = 1;
	if (keysym == XK_s || keysym == XK_Down)
		data->move.back = 1;
	if (keysym == XK_a)
		data->move.left = 1;
	if (keysym == XK_d)
		data->move.right = 1;
	if (keysym == XK_Left)
		data->move.rot_l = 1;
	if (keysym == XK_Right)
		data->move.rot_r = 1;
	if (keysym == XK_p)
		print_coords(data);
	return (0);
}

int	ft_key_release(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_Up)
		data->move.front = 0;
	if (keysym == XK_s || keysym == XK_Down)
		data->move.back = 0;
	if (keysym == XK_a)
		data->move.left = 0;
	if (keysym == XK_d)
		data->move.right = 0;
	if (keysym == XK_Left)
		data->move.rot_l = 0;
	if (keysym == XK_Right)
		data->move.rot_r = 0;
	if (keysym == XK_x)
	{
		data->cast.pov_x += 1;
		data->cast.pov_y += 1;
	}
	return (1);
}
