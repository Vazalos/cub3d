/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:32:52 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/26 10:54:19 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_init_mlx(t_data *data)
{
	data->mlx.mlx_ptr = NULL;
	data->img.img_ptr = NULL;
	data->mlx.window = NULL;
	data->mlx.mlx_ptr = mlx_init();
	if (!data->mlx.mlx_ptr)
		return (1);
	data->mlx.window = mlx_new_window(data->mlx.mlx_ptr, WIDTH, HEIGHT, TITLE);
	data->img.img_ptr = mlx_new_image(data->mlx.mlx_ptr, WIDTH, HEIGHT);
	if (!data->mlx.window || !data->img.img_ptr)
	{
		ft_free_mlx(data);
		return (1);
	}
	data->img.pix_addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	return (0);
}

void	ft_init_values(t_data *data)
{
	data->calc.pov_x = 3.5;
	data->calc.pov_y = 3.5;
	data->calc.dir_x = -1;
	data->calc.dir_y = 0;
	data->calc.plane_x = 0;
	data->calc.plane_y = 0.66;
	data->start_time = ft_get_time();
	data->time = data->start_time;
	data->old_time = data->start_time;
	data->move.front = 0;
	data->move.back = 0;
	data->move.left = 0;
	data->move.right = 0;
	data->move.rot_l = 0;
	data->move.rot_r = 0;
	data->calc.mouse_x = 5;
	data->calc.mouse_y = 5;
}

void	ft_init_textures(t_data *data)
{
	data->texture_size = TEX_SIZE;
	
	data->n_textr.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
		"no.xpm", &data->texture_size, &data->texture_size);
	data->n_textr.pix_addr = mlx_get_data_addr(data->n_textr.img_ptr, 
		&data->n_textr.bpp, &data->n_textr.line_len, &data->n_textr.endian);
	data->s_textr.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
		"so.xpm", &data->texture_size, &data->texture_size);
	data->s_textr.pix_addr = mlx_get_data_addr(data->s_textr.img_ptr, 
		&data->s_textr.bpp, &data->s_textr.line_len, &data->s_textr.endian);
	data->w_textr.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
		"we.xpm", &data->texture_size, &data->texture_size);
	data->w_textr.pix_addr = mlx_get_data_addr(data->w_textr.img_ptr, 
		&data->w_textr.bpp, &data->w_textr.line_len, &data->w_textr.endian);
	data->e_textr.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
		"ea.xpm", &data->texture_size, &data->texture_size);
	data->e_textr.pix_addr = mlx_get_data_addr(data->e_textr.img_ptr, 
		&data->e_textr.bpp, &data->e_textr.line_len, &data->e_textr.endian);
}
