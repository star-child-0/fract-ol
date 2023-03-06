/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:11:06 by gmattei           #+#    #+#             */
/*   Updated: 2023/03/01 20:04:28 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handler(int keycode, t_data *data)
{
	if (keycode == 4)
		data->zoom *= 1.1;
	else if (keycode == 5)
		data->zoom /= 1.1;
	else
		return (0);
	draw(data);
	return (1);
}

int	key_handler(int keycode, t_data *data)
{
	//ft_printf("key data: %p\n", data->mlx_ptr);
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
	else if (keycode == XK_x)
	{
		mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &data->mouse_x, &data->mouse_y);
		data->move_x += (data->mouse_x - data->small_side / 2);
		data->move_y += (data->mouse_y - data->small_side / 2);
		data->x_max /= 1.2;
		data->x_min /= 1.2;
		data->y_max /= 1.2;
		data->y_min /= 1.2;
		data->coord.max_iter += 3;
	}
	else if (keycode == XK_z)
	{
		data->zoom -= 20;
		data->coord.max_iter -= 3;
	}
	else
		return (0);
	draw(data);
	return (1);
}
