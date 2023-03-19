/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:10:29 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/19 18:41:21 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelship_equation(t_data *data)
{
	data->coord.px = 0;
	while (data->coord.px < data->small_side)
	{
		data->coord.py = 0;
		while (data->coord.py < data->small_side)
		{
			data->coord.iter = 0;
			data->coord.c.re = data->x_min + (data->coord.px + data->move_x)
				* (data->x_max - data->x_min) / data->small_side;
			data->coord.c.im = data->y_max - (data->coord.py + data->move_y)
				* (data->y_max - data->y_min) / data->small_side;
			mandelship_sequel(data);
			my_mlx_pixel_put(data, data->coord.px, data->coord.py, data->color
				* (data->coord.iter * 5));
			data->coord.py++;
		}
		data->coord.px++;
	}
	return (0);
}

void	mandelship_sequel(t_data *data)
{
	data->coord.z.re = 0;
	data->coord.z.im = 0;
	data->coord.z.re_sq = 0;
	data->coord.z.im_sq = 0;
	while (data->coord.z.re_sq + data->coord.z.im_sq < 4 && data->coord.iter
		< data->coord.max_iter)
	{
		if (data->fractal == 3)
			data->coord.z.im = fabs(2 * data->coord.z.re * data->coord.z.im)
				+ data->coord.c.im;
		else
			data->coord.z.im = 2 * data->coord.z.re * data->coord.z.im
				+ data->coord.c.im;
		data->coord.z.re = data->coord.z.re_sq - data->coord.z.im_sq
			+ data->coord.c.re;
		data->coord.z.re_sq = data->coord.z.re * data->coord.z.re;
		data->coord.z.im_sq = data->coord.z.im * data->coord.z.im;
		data->coord.iter++;
	}
}
