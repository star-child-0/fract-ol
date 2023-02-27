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
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 35, 0xffffff,
		"Arrow keys to move around");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 50, 0xffffff,
		"'C' to change the color range");
}

// Draw the fractal
void	draw(t_data *data)
{
	t_coords	coord;
	int			iterations;
	int			small_side;

	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	iterations = 0;
	small_side = WINDOW_HEIGHT;
	if (WINDOW_WIDTH < WINDOW_HEIGHT)
		small_side = WINDOW_WIDTH;
	while (coord.px <= WINDOW_WIDTH)
	{
		coord.py = 0;
		while (coord.py <= small_side)
		{
			coord.x = (((coord.px + data->x) - (small_side / data->zoom))
					/ (small_side / data->zoom)) * data->zoom;
			coord.y = (((small_side / data->zoom) - (coord.py + data->y))
					/ (small_side / data->zoom)) * data->zoom;
			iterations = ft_mandelbrot_pass(&coord);
			if (iterations < MAX_ITER)
				my_pixel_put(&data->img, coord.px, coord.py,
					data->color + iterations * 5);
			coord.py++;
		}
		coord.px++;
	}
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
	data->x = 0;
	data->y = 0;
	data->zoom = 2;
	data->color = 0x0000ff;
	draw(data);
	return (0);
}
