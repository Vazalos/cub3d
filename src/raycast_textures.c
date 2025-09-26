/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:06:15 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/26 11:56:20 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	wall_color(t_data *data)
{
	if (data->calc.side == 1)
	{
		if (data->calc.ray_dir_y < 0) //N
			data->calc.wall_color = RED;
		else //S
			data->calc.wall_color = GREEN;
	}
	else if (data->calc.side == 0)
	{
		if (data->calc.ray_dir_x < 0) //W
			data->calc.wall_color = BLUE;
		else //E
			data->calc.wall_color = YELLOW;
	}
}

	/*
		//color part
	if (data->calc.side == 1 && data->calc.ray_dir_y < 0) //N
		data->calc.wall_color = RED;
	else if (data->calc.side == 1 && data->calc.ray_dir_y >= 0) //S
		data->calc.wall_color = GREEN;
	else if (data->calc.side == 0 && data->calc.ray_dir_x < 0) //W
		data->calc.wall_color = BLUE;
	else if (data->calc.side == 0 && data->calc.ray_dir_x >= 0) //E
		data->calc.wall_color = YELLOW;
		*/
	/*
	if (map[data->calc.map_x][data->calc.map_y] == 1)
		data->calc.wall_color = RED;
	else if (map[data->calc.map_x][data->calc.map_y] == 2)
		data->calc.wall_color = GREEN;
	else if (map[data->calc.map_x][data->calc.map_y] == 3)
		data->calc.wall_color = BLUE;
	else
		data->calc.wall_color = YELLOW;
	if (data->calc.side == 1)
		data->calc.wall_color = data->calc.wall_color / 2;
	*/


void	wall_texture(t_data *data, int x)
{
	double	wall_x;
	int		texture_x;
	double	texture_step;
	double	texture_pos;
	int		texture_y;
	int		y;
	//unsigned int	tex_color;
	//void	*curr_texture;

	//calculate value of wallX
	if (data->calc.side == 1)
		wall_x = data->calc.pov_x + data->calc.perpend_wall_dist
			* data->calc.ray_dir_x;
	else
		wall_x = data->calc.pov_y + data->calc.perpend_wall_dist
			* data->calc.ray_dir_y;
	wall_x -= floor(wall_x);
	
	//x coordinate on the texture
	texture_x = (int)(wall_x * (double)TEX_SIZE);
	if (data->calc.side == 1 && data->calc.ray_dir_y > 0)
		texture_x = TEX_SIZE - texture_x - 1;
	if (data->calc.side == 0 && data->calc.ray_dir_x > 0)
		texture_x = TEX_SIZE - texture_x - 1;
		
	// How much to increase the texture coordinate per screen pixel
	texture_step = 1.0 * TEX_SIZE / data->calc.line_height;
	// Starting texture coordinate
	texture_pos = (data->calc.draw_start - (HEIGHT / 2)
			+ (data->calc.line_height / 2)) * texture_step;
	y = data->calc.draw_start;
	while (y < data->calc.draw_end)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		texture_y = (int)texture_pos & (TEX_SIZE - 1);
		texture_pos += texture_step;

		if (data->calc.side == 1 && data->calc.ray_dir_y < 0) //N
			data->calc.wall_color = *(unsigned int *)(data->n_textr.pix_addr + texture_y * data->n_textr.line_len
			+ texture_x * (data->n_textr.bpp / 8));
		else if (data->calc.side == 1 && data->calc.ray_dir_y >= 0) //S
			data->calc.wall_color = *(unsigned int *)(data->s_textr.pix_addr + texture_y * data->s_textr.line_len
			+ texture_x * (data->s_textr.bpp / 8));
		else if (data->calc.side == 0 && data->calc.ray_dir_x < 0) //W
			data->calc.wall_color = *(unsigned int *)(data->w_textr.pix_addr + texture_y * data->w_textr.line_len
			+ texture_x * (data->w_textr.bpp / 8));
		else if (data->calc.side == 0 && data->calc.ray_dir_x >= 0) //E
			data->calc.wall_color = *(unsigned int *)(data->e_textr.pix_addr + texture_y * data->e_textr.line_len
			+ texture_x * (data->e_textr.bpp / 8));
		//Uint32 color = texture[texNum][texHeight * texY + texX];
		//tex_color =  divide by viewing side;
		ft_draw_pixel(data, x, y, data->calc.wall_color);
		y++;

/*
		return (*(uint32_t *)(data->draw->textures[texture_idx].addr
		+ tex_Y * data->draw->textures[texture_idx].line_len
		+ data->vars->texture_x
		* (data->draw->textures[texture_idx].bpp / 8)));
		*/
	} 
}
