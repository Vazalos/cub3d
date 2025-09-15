#include "../includes/cub3d.h"

//draw_filled_circle(data, data->view.test_x, data->view.test_y, 5);

void draw_hline(t_data *data, int x1, int x2, int y) {
	for (int x = x1; x <= x2; ++x)
		ft_draw_pixel(data, x, y, RED);
}

// Highly performant integer-filled circle (uses scanlines)
void draw_filled_circle(t_data *data, int x0, int y0, int radius) {
	int x = 0;
	int y = radius;
	int d = 1 - radius;

	// Draw the center row
	draw_hline(data, x0 - radius, x0 + radius, y0);

	while (y > x) {
		if (d < 0) {
			d += 2 * x + 3;
		} else {
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;

		// Fill the horizontal lines for each scan
		draw_hline(data, x0 - x, x0 + x, y0 + y);
		draw_hline(data, x0 - x, x0 + x, y0 - y);
		draw_hline(data, x0 - y, x0 + y, y0 + x);
		draw_hline(data, x0 - y, x0 + y, y0 - x);
	}
}