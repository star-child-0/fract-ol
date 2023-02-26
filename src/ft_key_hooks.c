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
int	key_hook_handler(int keycode, t_data *data)
{
	static int x;
	static int y;
	static int color;

	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	if (keycode == XK_Escape)
	{
		mlx_loop_end(data->mlx_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	else if(keycode == XK_Up)
		y -= 100;
	else if(keycode == XK_Right)
		x += 100;
	else if(keycode == XK_Down)
		y += 100;
	else if(keycode == XK_Left)
		x -= 100;
	else if(keycode == XK_c)
		color += 0xf0A0f0;
	draw(data, x, y, color);
	return (0);
}

int	hook_close_handler(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}