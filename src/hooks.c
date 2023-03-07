/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:11:06 by gmattei           #+#    #+#             */
/*   Updated: 2023/03/07 20:37:13 by cscelfo          ###   ########.fr       */
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
	data->zoom = 1.1;
//	data->display_shift
	data->coord.max_iter = MAX_ITER;
}

void zoom_in(t_data *data, int px, int py)//funziona pochino
{
	data->zoom *= 1.1;
	double dx = (data->x_max - data->x_min) / 2;
	double dy = (data->y_max - data->y_min) / 2;
	data->mouse_x = data->x_min + (px + data->move_x) * (data->x_max - data->x_min) / data->small_side;
	data->mouse_y = data->y_min + (py + data->move_y) * (data->y_max - data->y_min) / data->small_side;
    data->x_min = data->mouse_x - dx / data->zoom;
    data->x_max = data->mouse_x + dx / data->zoom;
    data->y_min = data->mouse_y + dy / data->zoom;
    data->y_max = data->mouse_y - dy / data->zoom; //ciao gio
	data->coord.iter += px - py;
}

void zoom_out(t_data *data, int px, int py)//non FUNZIONAAAAAAAA
{
	data->zoom *= 1.1;
	double dx = (data->x_max + data->x_min) / 2;
	double dy = (data->y_max + data->y_min) / 2;
	data->mouse_x = data->x_min - (px + data->move_x) / (data->x_max - data->x_min) / data->small_side;
	data->mouse_y = data->y_min - (py + data->move_y) / (data->y_max - data->y_min) / data->small_side;
    data->x_min = data->mouse_x + dx / data->zoom;
    data->x_max = data->mouse_x - dx / data->zoom;
    data->y_min = data->mouse_y - dy / data->zoom;
    data->y_max = data->mouse_y + dy / data->zoom;
	data->coord.iter -= px - py;
}

int	mouse_handler(int keycode, int px, int py, t_data *data)
{
	if (keycode == 4)
		zoom_in(data, px, py);
	else if (keycode == 5)
		zoom_out(data, px, py);
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
