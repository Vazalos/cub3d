/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:39:46 by david-fe          #+#    #+#             */
/*   Updated: 2025/09/12 13:26:36 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void ft_draw_vertical(t_data *data, int x, int draw_start, int draw_end, int color)
{
    int y = draw_start;

    while (y < draw_end) //  <=?
    {
        ft_draw_pixel(data, x, y, color);
        y++;
    }
}

ft_raycast(t_data *data)
{
    int x = 0;
    
    int map[10][10] =
    {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,2,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1},
    };

    while (!done()) //CHANGE
    {
        while (x < WIDTH)
        {
            double camera_x = 2 * x / (double)WIDTH - 1;
            double ray_dir_x = data->view.dir_x + data->view.plane_x * camera_x;
            double ray_dir_y = data->view.dir_y + data->view.plane_y * camera_x;
            int map_x = (int)data->view.pov_x;
            int map_y = (int)data->view.pov_y;
            double side_dist_x;
            double side_dist_y;
            double delta_dist_x;
            double delta_dist_y;
            if (ray_dir_x == 0)
                delta_dist_x = HUGE_VAL;
            else
                fabs(1 / ray_dir_x);
            if (ray_dir_y == 0)
                delta_dist_y = HUGE_VAL;
            else
                fabs(1 / ray_dir_y);
                
            double perpend_wall_dist;
            int step_x;
            int step_y;
            int hit = 0;
            int side;
            if (ray_dir_x < 0)
            {
                step_x = -1;
                side_dist_x = (data->view.pov_x - map_x) * delta_dist_x;
            }
            else
            {
                step_x = 1;
                side_dist_x = (map_x + 1.0 - data->view.pov_x) * delta_dist_x;
            }
            if (ray_dir_y < 0)
            {
                step_y = -1;
                side_dist_y = (data->view.pov_y - map_y) * delta_dist_y;
            }
            else
            {
                step_y = 1;
                side_dist_y = (map_y + 1.0 - data->view.pov_y) * delta_dist_y;
            }
            while (hit == 0)
            {
                if (side_dist_x < side_dist_y)
                {
                    side_dist_x += delta_dist_x;
                    map_x += step_x;
                    side = 0;
                }
                else
                {
                    side_dist_y += delta_dist_y;
                    map_y += step_y;
                    side = 1;
                }
                if (map[map_x][map_y] > 0) hit = 1;
            }
            if (side == 0)
                perpend_wall_dist = (side_dist_x - delta_dist_x);
            else
                perpend_wall_dist = (side_dist_y - delta_dist_y);
            int line_height = (int)(HEIGHT / perpend_wall_dist);
            int draw_start = -line_height / 2 + HEIGHT / 2;
            if (draw_start < 0)
                draw_start = 0;
            int draw_end = line_height / 2 + HEIGHT / 2;
            if (draw_end >= HEIGHT)
                draw_end = HEIGHT - 1;

            int color;
            if (map[map_x][map_y] == 0)
                color = PURPLE;
            else if (map[map_x][map_y] == 1)
                color = RED;
            else if (map[map_x][map_y] == 2)
                color = GREEN;
            else if (map[map_x][map_y] == 3)
                color = BLUE;
            else 
                color = YELLOW;

            if(side == 1) {color = color / 2;}
            
            ft_draw_vertical(data, x, draw_start, draw_end, color);
            x++;
        }
        //while !done()
        data->old_time = data->time;
        data->time = ft_get_time();
        double frame_time = (data->time - data->old_time) / 1000.0;
        printf("%.2f\n", 1.0 / frame_time);
        
    }    
}