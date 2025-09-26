#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include "../mlx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>

#define WIDTH 1280
#define HEIGHT 720
#define TEX_SIZE 64
#define TITLE "David and Gustavo's Marvelous World of 3D"

#define SPEED_MOD 4
#define ROT_MOD 3

#define SKY 0xFF87CEEB
#define FLOOR 0xFF014421
#define WHITE 0xFFFFFFFF
#define BLACK 0xFF000000
#define RED 0xFFFF0000
#define GREEN 0xFF00FF00
#define BLUE 0xFF0000FF
#define YELLOW 0xFFFFFF00
#define PURPLE 0xFFFF00FF

typedef struct s_img
{
	void    *img_ptr;
	char    *pix_addr;
	int     bpp;
	int     line_len;
	int     endian;
} t_img;

typedef struct s_mlx
{
	void    *mlx_ptr;
	void    *window;
} t_mlx;

typedef struct s_calc
{
	double	mouse_x;
	double	mouse_y;
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
}   t_view;

typedef struct s_move
{
	double	speed;
	double	rotation;
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
	t_view	calc;
	t_move	move;
	int		texture_size;
	char	**map;
	double	start_time;
	double	time;
	double	old_time;
	double	frame_time;
	double	fps;
}   t_data;

// INITS
int     ft_init_mlx(t_data *data);
void    ft_init_values(t_data *data);
void	ft_init_textures(t_data *data);

//RENDER
int		render_frame(t_data *data);
double	ft_get_time(void);

// RAYCAST
void	ft_raycast(t_data *data);
void	get_base_coords(t_data *data, int x);

// RAYCAST_DIST
void	dist_per_square_x(t_data *data);
void	dist_per_square_y(t_data *data);
void	wall_hit_dist(t_data *data, int map[][10]);
void	wall_height(t_data *data);

//RAYCAST_TEXTURES
void	wall_color(t_data *data);
void	wall_texture(t_data *data, int x);

// FREES
int     ft_free_mlx(t_data *data);
int		ft_free_textures(t_data *data);

// PRINT
void	print_fps(double frame_duration);
void	print_coords(t_data *data);

// MOVE
void	frame_time_and_speed(t_data *data);
void	walk_front_and_back(t_data *data, int map[][10]);
void	walk_left_and_right(t_data *data, int map[][10]);
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);

// EVENTS
void    ft_event_handler(t_data *data);
int     ft_key_press(int keysym, t_data *data);
int		ft_key_release(int keysym, t_data *data);
int     ft_mouse_move(int x, int y, t_data *mlx);

// DRAW
void	ft_draw_pixel(t_data *data, int x, int y, int color);
void	ft_draw_vertical_line(t_data *data, int x);
void	ft_draw_crosshair(t_data *data, int x, int y);
void    ft_draw_background(t_data *data);


// COLOR
unsigned int	ft_argb_to_hex(unsigned int a, unsigned int r, unsigned int g, unsigned int b);
unsigned int	ft_hex_to_alpha(unsigned int hex);
unsigned int	ft_hex_to_red(unsigned int hex);
unsigned int	ft_hex_to_green(unsigned int hex);
unsigned int	ft_hex_to_blue(unsigned int hex);

#endif
