/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:15:54 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/27 17:35:41 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	window_labels(t_data *data)
{
	int color;

	color = 0xffffff;
	if(data->color >= color && data->color <= 0x808080)
		color = 0x000000;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 40, color, "Arrow keys to move around");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 60, color, "'C' to change the color range");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 80, color, "'X' to zoom in");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 100, color, "'Z' to zoom out");
}

// Draw the fractal
void	draw(t_data *data)
{
	t_coords	coord;
	int			iterations;
	int			small_side;
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	iterations = 0;
	small_side = WINDOW_HEIGHT;
	if (WINDOW_WIDTH < WINDOW_HEIGHT)
		small_side = WINDOW_WIDTH;
	while (coord.px <= WINDOW_WIDTH)
	{
		coord.py = 0;
		while (coord.py <= small_side)
		{
			coord.x = (((coord.px + data->add_px) - (small_side / data->zoom)) / (small_side / data->zoom)) * data->zoom;
			coord.y = (((small_side / data->zoom) - (coord.py + data->add_py)) / (small_side / data->zoom)) * data->zoom;
			iterations = ft_mandelbrot_pass(&coord);
			if (iterations < MAX_ITER)
				my_pixel_put(&data->img, coord.px, coord.py,
					data->color + pow(iterations, 5.5));
			coord.py++;
		}
		coord.px++;
	}
	//ft_printf("\n\npx: %d, py: %d, coord->x: %d, coord->y: %d, data->x: %d, data->y:%d\n\n", coord.px, coord.py, coord.x, coord.y, data->add_px, data->add_py);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	window_labels(data);
}

// Draw handler
int	draw_handle(t_data *data)
{
	t_coords	coord;

	if (data->win_ptr == NULL)
		return (1);
	coord.px = 0;
	data->add_px = 0;
	data->add_py = 0;
	data->zoom = 2;
	data->color = 0x808080;
	draw(data);
	return (0);
}
