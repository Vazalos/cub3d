/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:32:52 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/13 15:58:31 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_all(t_data *data, t_map *map)
{
	ft_bzero(data, sizeof(t_data));
	data->map = map;
	ft_init_mlx(data);
	ft_init_values(data);
	ft_init_textures(data, map);
}

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
	data->cast.pov.x = data->map->playersx;
	data->cast.pov.y = data->map->playersy;
	if (data->map->playero == 'N')
		data->cast.dir.y = -1;
	else if (data->map->playero == 'S')
		data->cast.dir.y = 1;
	else if (data->map->playero == 'E')
		data->cast.dir.x = 1;
	else if (data->map->playero == 'W')
		data->cast.dir.x = -1;
	if (data->cast.dir.y == 0)
		data->cast.plane.y = -0.66 * (-data->cast.dir.x);
	else if (data->cast.dir.x == 0)
		data->cast.plane.x = 0.66 * (-data->cast.dir.y);
	data->start_time = ft_get_time();
	data->current_time = data->start_time;
	data->old_time = data->start_time;
	data->window_focus = 1;
}

void	ft_init_textures(t_data *data, t_map *map)
{
	data->n_textr.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			map->no, &data->textr_height, &data->textr_width);
	data->s_textr.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			map->so, &data->textr_height, &data->textr_width);
	data->w_textr.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			map->we, &data->textr_height, &data->textr_width);
	data->e_textr.img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			map->ea, &data->textr_height, &data->textr_width);
	if(data->n_textr.img_ptr && data->s_textr.img_ptr && data->w_textr.img_ptr
		&& data->e_textr.img_ptr)
		ft_init_texture_addresses(data);
	else
	{
		ft_putstr_fd("Error: Invalid texture(s)\n", 2);
		ft_free_mlx(data);
	}
}

void	ft_init_texture_addresses(t_data *data)
{
	data->n_textr.pix_addr = mlx_get_data_addr(data->n_textr.img_ptr,
			&data->n_textr.bpp, &data->n_textr.line_len, &data->n_textr.endian);
	data->s_textr.pix_addr = mlx_get_data_addr(data->s_textr.img_ptr,
			&data->s_textr.bpp, &data->s_textr.line_len, &data->s_textr.endian);
	data->w_textr.pix_addr = mlx_get_data_addr(data->w_textr.img_ptr,
			&data->w_textr.bpp, &data->w_textr.line_len, &data->w_textr.endian);
	data->e_textr.pix_addr = mlx_get_data_addr(data->e_textr.img_ptr,
			&data->e_textr.bpp, &data->e_textr.line_len, &data->e_textr.endian);
	if (!data->n_textr.pix_addr || !data->s_textr.pix_addr
		|| !data->w_textr.pix_addr || !data->e_textr.pix_addr)
	{
		ft_putstr_fd("Error: Invalid texture(s)\n", 2);
		ft_free_mlx(data);
	}
}		
