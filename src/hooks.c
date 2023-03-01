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

int hook_handler(int keycode, t_fractal *fractal)
{
    if(!mouse_handler(keycode) || !key_handler(keycode, fractal))
        return(0);
    //draw
    return(1);
}

int mouse_handler(int keycode)
{
    if(keycode == 4)//scroll up
        printf("scroll up");
    else if(keycode == 5)//scroll down
        printf("scroll down");
    else
        return(0);
    return(1);
}

int key_handler(int keycode, t_fractal *fractal)
{
    if(keycode == XK_Escape)
    {
        end_fractal(fractal);
        return(0);
    }
    else if(keycode == XK_Up)
        printf("Up");
    else if(keycode == XK_Right)
        printf("Right");
    else if(keycode == XK_Down)
        printf("Down");
    else if(keycode == XK_Left)
        printf("Left");
    else if(keycode == XK_c) //color shift
        printf("Color Shift");
    else
        return(0);
    return(1);
}
