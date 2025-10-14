/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:54:42 by david-fe          #+#    #+#             */
/*   Updated: 2025/10/14 16:33:58 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include "../mlx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include "../src/parsing/parsing.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

# define WIDTH 1280
# define HEIGHT 720

# define TEX_SIZE 255
# define TITLE "David and Gustavo's Marvelous World of 3D"

# define DELTA_MULT 5

# define SPEED_MOD 5 //originally 5
# define ROTATION_MOD 2.4 //originally 3
# define FOV 60

# define SKY 0xFF87CEEB
# define FLOOR 0xFF014421
# define WHITE 0xFFFFFFFF
# define BLACK 0xFF000000
# define GRAY 0xFF888888
# define RED 0xFFFF0000
# define GREEN 0xFF00FF00
# define BLUE 0xFF0000FF
# define YELLOW 0xFFFFFF00
# define PURPLE 0xFFFF00FF

typedef struct s_img
{
	void	*img_ptr;
	char	*pix_addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window;
}	t_mlx;

typedef struct s_mouse
{
	double	x;
	double	y;
	double	offset_x;
	double	old_x;
}	t_mouse;

typedef struct s_minimap
{
	int		center_x;
	int		center_y;
	int		scale;
	int 	start_x;
	int 	start_y;
	int		end_x;
	int		end_y;
	int		facing_x;
	int		facing_y;
	int		view_radius;
	int		view_size;
}	t_mmap;

typedef struct s_cast
{
	double	pov_x; //pov coordinates
	double	pov_y;
	double	dir_x; //direction from pov
	double	dir_y;
	double	plane_x; //perpendicular to direction
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perpend_wall_dist;
	int		step_x;
	int		step_y;
	int		wall_hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		wall_color;
}	t_cast;

typedef struct s_move
{
	double	accel_f;
	double	accel_b;
	double	accel_l;
	double	accel_r;
	double	speed;
	double	rot;
	int		front;
	int		back;
	int		left;
	int		right;
	int		rot_l;
	int		rot_r;
}	t_move;

typedef struct s_data
{
	t_img	img;
	t_img	n_textr;
	t_img	s_textr;
	t_img	e_textr;
	t_img	w_textr;
	t_mlx	mlx;
	t_cast	cast;
	t_move	move;
	t_mouse	mouse;
	t_mmap	mmap;
	int		texture_size;
	double	start_time;
	double	time;
	double	old_time;
	double	frame_time;
	int		fps;
	t_map	*map;
	t_map	**parse_map;
}	t_data;

// INITS
void	ft_init_all(t_data *data, t_map *map);
int		ft_init_mlx(t_data *data);
void	ft_init_values(t_data *data);
void	ft_init_textures(t_data *data);

// MINIMAP
void	init_minimap(t_data *data);
void	draw_minimap(t_data *data);
void	draw_square(t_data *data, int x, int y, unsigned int color, int alpha);
void	draw_player_dir(t_data *data, int x0, int y0);
unsigned int get_alpha_color(t_data *data, int target_x, int target_y,
	unsigned int new_color);

// RENDER
int		render_frame(t_data *data);
double	ft_get_time(void);

// RAYCAST
void	frame_time_and_speed(t_data *data);
void	ft_raycast(t_data *data);

// RAYCAST_DIST
void	get_base_coords(t_data *data, int x);
void	dist_per_square_x(t_data *data);
void	dist_per_square_y(t_data *data);
void	wall_hit_dist(t_data *data);
void	wall_height(t_data *data);

//RAYCAST_TEXTURES
void	wall_color(t_data *data, int x);
void	wall_texture(t_data *data, int x);
void	wall_texture_step(t_data *data, int x, int texture_x);
void	get_wall_texture_pixel(t_data *data, int texture_x, int texture_y);

// FREES
int		ft_free_mlx(t_data *data);
int		ft_free_textures(t_data *data);

// PRINT
void	ft_fps_in_window(t_data *data);
void	print_fps(int fps);
void	print_coords(t_data *data);

// MOVE
void	walk_front_and_back(t_data *data);
void	walk_left_and_right(t_data *data);
void	rotate_player(t_data *data);
void	rotate_with_mouse(t_data *data);

// EVENTS
void	ft_event_handler(t_data *data);
int		ft_key_press(int keysym, t_data *data);
int		ft_key_release(int keysym, t_data *data);
int		ft_mouse_move(int x, int y, t_data *mlx);

// DRAW
void		ft_draw_pixel(t_data *data, int x, int y, int color);
void		ft_draw_vertical_line(t_data *data, int x);
void		ft_draw_crosshair(t_data *data, int x, int y);
void		ft_draw_background(t_data *data);

// COLOR
unsigned int	ft_argb_to_hex(unsigned int a, unsigned int r, unsigned int g,
			unsigned int b);
unsigned int	ft_hex_to_alpha(unsigned int hex);
unsigned int	ft_hex_to_red(unsigned int hex);
unsigned int	ft_hex_to_green(unsigned int hex);
unsigned int	ft_hex_to_blue(unsigned int hex);

// CLEANUP
void	ft_free_split(char **str);

#endif
