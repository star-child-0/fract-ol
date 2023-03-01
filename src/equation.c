/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:09:55 by gmattei           #+#    #+#             */
/*   Updated: 2023/03/01 15:09:56 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    ft_printf("pixel: %s", pixel);
	*(int *)pixel = color;
}

int equation(t_data *data)
{
    data->coord.x = 0;
    while(data->coord.x < WIN_WIDTH)
    {
        data->coord.y = 0;
        while(data->coord.y < WIN_HEIGHT)
        {
            data->coord.cr = data->coord.x / data->zoom - 2;
            data->coord.ci = data->coord.y / data->zoom - 2;
            data->coord.zr = 0;
            data->coord.zi = 0;
            while(data->coord.zr * data->coord.zr + data->coord.zi * data->coord.zi < 4 && data->coord.iter < MAX_ITER)
            {
                data->coord.tmp = data->coord.zr;
                data->coord.zr = data->coord.zr * data->coord.zr - data->coord.zi * data->coord.zi + data->coord.cr;
                data->coord.zi = 2 * data->coord.tmp * data->coord.zi + data->coord.ci;
                data->coord.iter++;
            }
            if(data->coord.iter == MAX_ITER)
                my_mlx_pixel_put(&data->img, data->coord.x, data->coord.y, 0x000000);
            else
            {
                my_mlx_pixel_put(data->img.mlx_img, data->coord.x, data->coord.y, data->color * data->coord.iter);
                ft_printf("x: %f, y: %f, iter: %d", data->coord.x, data->coord.y, data->coord.iter);
            }
            data->coord.y++;
        }
        data->coord.x++;
    }
    return(0);
}