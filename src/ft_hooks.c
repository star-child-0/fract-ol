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
void key_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_loop_end(data->mlx_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	else if(keycode == XK_Up)
		data->y -= 100;
	else if(keycode == XK_Right)
		data->x += 100;
	else if(keycode == XK_Down)
		data->y += 100;
	else if(keycode == XK_Left)
		data->x -= 100;
	else if(keycode == XK_c)
		data->color += 0xf0A0f0;
	else if(keycode == XK_x)
		data->zoom /= 2;
}



int	hook_handler(int keycode, t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	key_handler(keycode, data);
	draw(data);
	return (0);
}

int	hook_close_handler(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int mouse_hook_handler(int button, t_data *data)
{
	ft_printf("here");
	(void)button;
	//(void)data;
	data->zoom /= 2;
	/* if(button == 4)
	{
		data->color /= 2;
	}
	if(button == 5)
	{
		data->zoom *= 2;
	} */
	return(0);
}