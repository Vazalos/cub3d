/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:50:23 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/23 14:52:51 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	on_focus(t_data *data)
{
	data->window_focus = 1;
	return (0);
}

int	off_focus(t_data *data)
{
	data->window_focus = 0;
	return (0);
}

void	toggle_minimap(t_data *data)
{
	if (data->mmap.hide_minimap == 0)
		data->mmap.hide_minimap = 1;
	else
		data->mmap.hide_minimap = 0;
}

void	toggle_debug(t_data *data)
{
	if (data->print_debug_info == 0)
		data->print_debug_info = 1;
	else
		data->print_debug_info = 0;
}

void	toggle_mouse_hide(t_data *data)
{
	if (data->mouse_hide == 0)
	{
		data->mouse_hide = 1;
		mlx_mouse_show(data->mlx.mlx_ptr, data->mlx.window);
	}
	else
	{
		data->mouse_hide = 0;
		mlx_mouse_hide(data->mlx.mlx_ptr, data->mlx.window);
	}
}
