/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:31:46 by cscelfo           #+#    #+#             */
/*   Updated: 2023/03/06 20:06:19 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
				* data->coord.iter * 4200);
			data->coord.py++;
		}
		data->coord.px++;
	}
	return (0);
}

void	equation2(t_data *data)
{
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
