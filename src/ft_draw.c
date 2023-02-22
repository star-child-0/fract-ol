/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:15:54 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/22 18:23:31 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	ft_blue(t_data *data, int iterations, float px, float py)
{
	int			blue;

	blue = 0x0000FF;
	if (iterations < MAX_ITER)
		my_pixel_put(&data->img, px, py, blue + iterations * 5);
}

// Draw the fractal
int	draw(t_data *data)
{
	t_coords	coord;
	int			iterations;

	coord.px = 0;
	coord.py = 0;
	iterations = 0;
	if (data->win_ptr == NULL)
		return (1);
	while (coord.px <= WINDOW_WIDTH)
	{
		coord.py = 0;
		while (coord.py <= WINDOW_HEIGHT)
		{
			coord.x = ((coord.px - (WINDOW_WIDTH / 2))
					/ (WINDOW_WIDTH / 2)) * 2;
			coord.y = (((WINDOW_HEIGHT / 2) - coord.py)
					/ (WINDOW_HEIGHT / 2)) * 2;
			iterations = ft_pass(&coord);
			ft_blue(data, iterations, coord.px, coord.py);
			coord.py++;
		}
		coord.px++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
//	mlx_loop_end(data->mlx_ptr);
	return (0);
}
// x = ((px - 100) / 100) * 2;
// y = ((100 - py) / 100) * 2;
// printf("px=[%d] | py=[%d] | operation=[%f]\n", px, py, (float)((px - WINDOW_WIDTH / 2) / (float)(WINDOW_WIDTH / 2) * 2));
// printf("px=[%f] | py=[%f] | x=[%f] | y=[%f] | iterations done=[%d]\n\n", px, py, x, y, iterations);
// mlx_clear_window(data->mlx_ptr, data->win_ptr);
