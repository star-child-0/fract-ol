/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:09:55 by gmattei           #+#    #+#             */
/*   Updated: 2023/03/01 20:14:22 by anvannin         ###   ########.fr       */
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
	data->coord.x = 0;
	while (data->coord.x < WIN_WIDTH)
	{
		data->coord.y = 0;
		while (data->coord.y < WIN_HEIGHT)
		{
			data->coord.iter = 0;
			data->coord.cr = data->coord.x / MAX_ITER - data->zoom;
			data->coord.ci = data->coord.y / MAX_ITER - data->zoom;
			data->coord.zr = 0;
			data->coord.zi = 0;
			equation2(data);
			my_mlx_pixel_put(data, data->coord.x, data->coord.y, 0x080808
				* pow(data->coord.iter, 1.75));
			data->coord.y++;
		}
		data->coord.x++;
	}
	return (0);
}

void	equation2(t_data *data)
{
	while (data->coord.zr * data->coord.zr + data->coord.zi
		* data->coord.zi < 4 && data->coord.iter < MAX_ITER)
	{
		data->coord.tmp = data->coord.zr;
		data->coord.zr = data->coord.zr * data->coord.zr
			- data->coord.zi * data->coord.zi + data->coord.cr;
		data->coord.zi = 2 * data->coord.tmp * data->coord.zi
			+ data->coord.ci;
		data->coord.iter++;
	}
}