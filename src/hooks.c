/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:11:06 by gmattei           #+#    #+#             */
/*   Updated: 2023/03/01 12:11:06 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int hook_handler(int keycode, t_data *data)
{
    if(mouse_handler(keycode, data) || key_handler(keycode, data))
    {
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
                data->img.mlx_img, 0, 0);
    }
    else
        return(0);
    return(1);
}

int mouse_handler(int keycode, t_data *data)
{
    if(keycode == 4)//scroll up
        data->zoom /= 1.1;
    else if(keycode == 5)//scroll down
        data->zoom *= 1.1;
    else
        return(0);
    return(1);
}

int key_handler(int keycode, t_data *data)
{
    if(keycode == XK_Escape)
    {
        end_fractal(data);
        return(0);
    }
    else if(keycode == XK_Up)
        ft_printf("Up");
    else if(keycode == XK_Right)
        ft_printf("Right");
    else if(keycode == XK_Down)
        ft_printf("Down");
    else if(keycode == XK_Left)
        ft_printf("Left");
    else if(keycode == XK_c) //color shift
        ft_printf("Color Shift");
    else
        return(0);
    return(1);
}
