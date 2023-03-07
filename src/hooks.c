/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:11:06 by gmattei           #+#    #+#             */
/*   Updated: 2023/03/06 18:02:23 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void reset_fractal(t_data *data)
{
	data->move_x = 0;
	data->move_y = 0;
	data->x_max = 2;
	data->x_min = -2;
	data->y_max = 2;
	data->y_min = -2;
	data->coord.max_iter = MAX_ITER;
}

void zoom_in(t_data *data)
{
	data->move_x += (data->mouse_x - data->small_side / 2) / 2;
	data->move_y += (data->mouse_y - data->small_side / 2) / 2;
	data->x_max /= 1.2;
	data->x_min /= 1.2;
	data->y_max /= 1.2;
	data->y_min /= 1.2;	
	data->coord.max_iter += 5;
}

void zoom_out(t_data *data)
{
	data->move_x -= (data->mouse_x - data->small_side / 2) / 2;
	data->move_y -= (data->mouse_y - data->small_side / 2) / 2;
	data->x_max *= 1.2;
	data->x_min *= 1.2;
	data->y_max *= 1.2;
	data->y_min *= 1.2;
	data->coord.max_iter -= 5;
}

int	mouse_handler(int keycode, int x, int y, t_data *data)
{
	mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &data->mouse_x, &data->mouse_y);
	x = data->mouse_x;
	y = data->mouse_y;
	if (keycode == 4)
		zoom_in(data);
	else if (keycode == 5)
		zoom_out(data);
	else
		return (0);
	draw(data);
	return (1);
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		end_fractal(data);
		return (0);
	}
	else if (keycode == XK_Up)
		data->move_y -= WIN_HEIGHT / 20;
	else if (keycode == XK_Left)
		data->move_x -= WIN_WIDTH / 20;
	else if (keycode == XK_Down)
		data->move_y += WIN_HEIGHT / 20;
	else if (keycode == XK_Right)
		data->move_x += WIN_WIDTH / 20;
	else if (keycode == XK_c)
		data->color += 0x080808;
	else if (keycode == XK_r)
		reset_fractal(data);
	else
		return (0);
	draw(data);
	return (1);
}