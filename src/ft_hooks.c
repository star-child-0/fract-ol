/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:09:52 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/25 17:11:38 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Press ESC to close the window
int key_hook_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		hook_close_handler(data);
		return (0);
	}
	else if(keycode == XK_Up)
		data->add_py -= 100;
	else if(keycode == XK_Right)
		data->add_px += 100;
	else if(keycode == XK_Down)
		data->add_py += 100;
	else if(keycode == XK_Left)
		data->add_px -= 100;
	else if(keycode == XK_c)
		data->color += 0xf0A0f0;
	else if(keycode == XK_x)//zoom in base
		data->zoom /= 1.2;
	else if(keycode == XK_z)//zoom out base
		data->zoom *= 1.2;
	else
		return (0);
	return(1);
	//zoom in puntato
	//zoom out puntato
	//mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &data->x, &data->y);
	//zoom stupido
}

int	hook_handler(int keycode, t_data *data)
{
	if (!key_hook_handler(keycode, data))
		return (0);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	draw(data);
	return (1);
}

int	hook_close_handler(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}