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
	data->zoom = 1.0;
	data->color = 0xBB00AA;
	data->coord.max_iter = MAX_ITER;
}

void zoom_in(t_data *data, int px, int py)//funziona fino a 
{
	float	mouse_pos_x;
	float	mouse_pos_y;
	double	zoom_decr;
	double	new_zoom;
	double	zoom_factor;
	mouse_pos_x = data->x_min + (px + data->move_x) * (data->x_max - data->x_min) / data->small_side;
	mouse_pos_y = data->y_max - (data->move_y + py) * (data->y_max - data->y_min) / data->small_side;
	zoom_decr = data->zoom / 10;
	new_zoom = fabs((double)data->zoom - zoom_decr);
	if (new_zoom <= zoom_decr)
	{
		data->zoom_decr /= 10;
		data->new_zoom = data->zoom - data->zoom_decr;	
	}
	data->zoom_factor = data->new_zoom / data->zoom;
	data->x_min = data->mouse_pos_x - (data->mouse_pos_x - data->x_min) * data->zoom_factor;
	data->x_max = data->mouse_pos_x + (data->x_max - data->mouse_pos_x) * data->zoom_factor;
	data->y_min = data->mouse_pos_y - (data->mouse_pos_y - data->y_min) * data->zoom_factor;
	data->y_max = data->mouse_pos_y + (data->y_max - data->mouse_pos_y) * data->zoom_factor;
	data->zoom = data->new_zoom;
	data->coord.max_iter += 5;
	//printf("\n\ndata->mouse_pos_x: %f\ndata->mouse_pos_y: %f\ndata->zoom_decr: %lf\ndata->new_zoom: %lf\ndata->zoom_factor: %lf\nx_min: %f\nx_max: %f\ny_min: %f\ny_max: %f\nzoom: %f\nmax_iter: %d\n\n", data->mouse_pos_x, data->mouse_pos_y, data->zoom_decr, data->new_zoom, data->zoom_factor, data->x_min, data->x_max, data->y_min, data->y_max, data->zoom, data->coord.max_iter);
}

void zoom_out(t_data *data, int px, int py)//non FUNZIONAAAAAAAA
{
	data->mouse_pos_x = data->x_min + (px + data->move_x) * (data->x_max - data->x_min) / data->small_side;
	data->mouse_pos_y = data->y_max - (data->move_y + py) * (data->y_max - data->y_min) / data->small_side;
	data->zoom_incr = data->zoom / 10;
	data->new_zoom = fabsl((double)data->zoom + data->zoom_incr);
	if (data->new_zoom <= data->zoom_incr)
	{
		data->zoom_incr /= 10;
		data->new_zoom = data->zoom + data->zoom_incr;	
	}
	data->zoom_factor = data->new_zoom / data->zoom;
	data->x_min = data->mouse_pos_x - (data->mouse_pos_x - data->x_min) * data->zoom_factor;
	data->x_max = data->mouse_pos_x + (data->x_max - data->mouse_pos_x) * data->zoom_factor;
	data->y_min = data->mouse_pos_y - (data->mouse_pos_y - data->y_min) * data->zoom_factor;
	data->y_max = data->mouse_pos_y + (data->y_max - data->mouse_pos_y) * data->zoom_factor;
	data->zoom = data->new_zoom;
	data->coord.max_iter -= 5;
	//printf("\n\ndata->mouse_pos_x: %f\ndata->mouse_pos_y: %f\nzoom_incr: %lf\ndata->new_zoom: %lf\ndata->zoom_factor: %lf\nx_min: %f\nx_max: %f\ny_min: %f\ny_max: %f\nzoom: %f\nmax_iter: %d\n\n", data->mouse_pos_x, data->mouse_pos_y, zoom_incr, data->new_zoom, data->zoom_factor, data->x_min, data->x_max, data->y_min, data->y_max, data->zoom, data->coord.max_iter);
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
		data->color *= 5;
	else if (keycode == XK_r)
		reset_fractal(data);
	else
		return (0);
	draw(data);
	return (1);
}
