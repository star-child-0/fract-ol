/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:09:55 by gmattei           #+#    #+#             */
/*   Updated: 2023/03/06 15:47:30 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	*pixel;

	pixel = (int *)&data->img.addr[y * data->img.line_len + x
		*(data->img.bpp / 8)];
	*pixel = color;
}

int	equation(t_data *data)
{
	data->coord.px = 0;
	while (data->coord.px < data->small_side)
	{
		data->coord.py = 0;
		while (data->coord.py < data->small_side)
		{
			data->coord.iter = 0;
			data->coord.c.re = data->x_min + (data->coord.px + data->move_x) * (data->x_max - data->x_min) / data->small_side;
			data->coord.c.im = data->y_max - (data->coord.py + data->move_y) * (data->y_max - data->y_min) / data->small_side;
			equation2(data);
			my_mlx_pixel_put(data, data->coord.px, data->coord.py, data->color
				* (data->coord.iter / data->coord.max_iter * 0x0000FF) * (data->coord.iter / data->coord.max_iter * 0xFF0000) );
			data->coord.py++;
		}
		data->coord.px++;
	}
	return (0);
}

void	equation2(t_data *data)
{
	data->coord.z.re = 0;
	data->coord.z.im = 0;
	data->coord.z.re_sq = 0;
	data->coord.z.im_sq = 0;
	while (data->coord.z.re_sq + data->coord.z.im_sq < 4 && data->coord.iter < data->coord.max_iter)
	{
		data->coord.z.im = 2 * data->coord.z.re * data->coord.z.im
			+ data->coord.c.im;
		data->coord.z.re = data->coord.z.re_sq - data->coord.z.im_sq + data->coord.c.re;
		data->coord.z.re_sq = data->coord.z.re * data->coord.z.re;
		data->coord.z.im_sq = data->coord.z.im * data->coord.z.im;
		data->coord.iter++;
	}
}

void	draw(t_data *data)
{
	if(data->mouse_x > WIN_WIDTH)
		data->mouse_x = WIN_WIDTH;
	if(data->mouse_y > WIN_HEIGHT)
		data->mouse_y = WIN_HEIGHT;
	if(data->mouse_y < 0)
		data->mouse_y = 0;
	equation(data);
	printf("mouse_x: %d, mouse_y: %d, move_x: %d, move_y: %d, x_min: %f, x_max: %f, y_min: %f, y_max: %f, iter:%d\n", data->mouse_x, data->mouse_y, data->move_x, data->move_y, data->x_min, data->x_max, data->y_min, data->y_max, data->coord.max_iter);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	window_labels(data);
}

void	window_labels(t_data *data)
{
	int color;

	color = 0xffffff;
	if(data->color >= color - 0x080808 && data->color <= 0x080808)
		color = 0x000000;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 40, color, "Arrow keys to move around");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 60, color, "'C' to change the color range");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 80, color, "Mouse wheel to zoom in and out");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 100, color, "'r' to reset the view");
}
