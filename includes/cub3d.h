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
#define TITLE "David and Gustavo's Marvelous World of 3D"

#define SKY 0xFF000000
#define FLOOR 0xFFFFFFFF
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

typedef struct s_view
{
    double   mouse_x;
    double   mouse_y;

    double   pov_x; //pov coordinates
    double   pov_y;
    double   dir_x; //direction from pov
    double   dir_y;
    double   dir_len;
    double   plane_x; //perpendicular to direction
    double   plane_y;

}   t_view;

typedef struct s_data
{
    t_img       img;
    t_mlx       mlx;
    t_view      view;
    char        **map;
    double      start_time;
    double      time;
    double      old_time;
}   t_data;

size_t	ft_get_time(void);

// INITS
int     ft_init_mlx(t_data *data);
void    ft_init_values(t_data *data);

// FREES
int     ft_free_mlx(t_data *data);

// EVENTS
void    ft_event_handler(t_data *data);
int     ft_keypress(int keysym, t_data *data);
int     ft_mouse_move(int x, int y, t_data *mlx);

// DRAW
void    ft_draw_background(t_data *data);
void    ft_draw_pixel(t_data *data, int x, int y, int color);

// COLOR
unsigned int	ft_argb_to_hex(unsigned int a, unsigned int r, unsigned int g, unsigned int b);
unsigned int	ft_hex_to_alpha(unsigned int hex);
unsigned int	ft_hex_to_red(unsigned int hex);
unsigned int	ft_hex_to_green(unsigned int hex);
unsigned int	ft_hex_to_blue(unsigned int hex);

#endif
