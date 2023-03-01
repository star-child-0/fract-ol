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
		data->zoom /= 1.1;
	else if (keycode == 5)
		data->zoom *= 1.1;
	else
		return (0);
	return (1);
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		end_fractal(data);
		return (0);
	}
	if (keycode == XK_Up)
		ft_printf("Up\n");
	else if (keycode == XK_Right)
		ft_printf("Right\n");
	else if (keycode == XK_Down)
		ft_printf("Down\n");
	else if (keycode == XK_Left)
		ft_printf("Left\n");
	else if (keycode == XK_c)
		ft_printf("Color Shift\n");
	else
		return (0);
	return (1);
}
