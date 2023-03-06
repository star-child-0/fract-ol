/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:09:55 by gmattei           #+#    #+#             */
/*   Updated: 2023/03/03 17:52:18 by cscelfo          ###   ########.fr       */
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
	data->small_side = get_small_side();
	data->coord.px = 0;
	while (data->coord.px < data->small_side)
	{
		data->coord.py = 0;
		while (data->coord.py < data->small_side)
		{
			data->coord.iter = 0;
			data->coord.cr = (data->coord.px  + data->move_x) / data->small_side / 62 * data->zoom - 2;
			data->coord.ci = (data->coord.py  + data->move_y) / data->small_side / 62 * data->zoom - 2;
			if (data->coord.cr * data->coord.cr + data->coord.ci * data->coord.ci > 4 && data->coord.iter++)
				break ;
			data->coord.zr = 0;
			data->coord.zi = 0;
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

void	draw(t_data *data)
{
	equation(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	window_labels(data);
}

void	window_labels(t_data *data)
{
	int color;

	color = 0xffffff;
	if(data->color >= color && data->color <= 0x808080)
		color = 0x000000;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 40, color, "Arrow keys to move around");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 60, color, "'C' to change the color range");
}
