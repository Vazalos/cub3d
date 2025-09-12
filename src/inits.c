/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:32:52 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/11 11:48:13 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_init_mlx(t_data *data)
{
    data->mlx.mlx_ptr = NULL;
    data->img.img_ptr = NULL;
    data->mlx.window = NULL;    
    data->mlx.mlx_ptr = mlx_init();
    if(!data->mlx.mlx_ptr)
        return(1);
    data->mlx.window = mlx_new_window(data->mlx.mlx_ptr, WIDTH, HEIGHT, TITLE);
    data->img.img_ptr = mlx_new_image(data->mlx.mlx_ptr, WIDTH, HEIGHT);
    if(!data->mlx.window || !data->img.img_ptr)
    {
        ft_free_mlx(data);
        return(1);
    }
    data->img.pix_addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
            &data->img.line_len, &data->img.endian);
    return(0);
}