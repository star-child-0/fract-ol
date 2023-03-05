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
	ft_printf("mouse data: %p\n", data->mlx_ptr);
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
		data->zoom += 20;
	}
	else if (keycode == XK_z)
	{
		data->zoom -= 20;
	}
	else
		return (0);
	draw(data);
	return (1);
}
