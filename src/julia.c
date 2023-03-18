/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:20:26 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/18 17:32:45 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_equation_init(t_data *data)
{
	data->coord.iter = 0;
	data->coord.z.re = data->x_min + (data->coord.px + data->move_x)
		* (data->x_max - data->x_min) / data->small_side;
	data->coord.z.im = data->y_max - (data->coord.py + data->move_y)
		* (data->y_max - data->y_min) / data->small_side;
}

int	julia_equation(t_data *data)
{
	data->coord.px = 0;
	while (data->coord.px < data->small_side)
	{
		data->coord.py = 0;
		while (data->coord.py < data->small_side)
		{
			julia_equation_init(data);
			julia_sequel(data);
			my_mlx_pixel_put(data, data->coord.px, data->coord.py,
				data->coord.iter * data->color * 5);
			data->coord.py++;
		}
		data->coord.px++;
	}
	return (0);
}

void	julia_sequel(t_data *data)
{
	double	temp;

	while (data->coord.z.re * data->coord.z.re + data->coord.z.im
		* data->coord.z.im < 4 && data->coord.iter
		< data->coord.max_iter)
	{
		temp = data->coord.z.re;
		data->coord.z.re = data->coord.z.re * data->coord.z.re
			- data->coord.z.im * data->coord.z.im + data->coord.c.re;
		data->coord.z.im = 2 * temp * data->coord.z.im
			+ data->coord.c.im;
		data->coord.iter++;
	}
}
