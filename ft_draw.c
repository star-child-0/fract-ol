/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:15:54 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/21 16:55:02 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int draw(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (data->win_ptr == NULL)
		return (1);
	while(j < WINDOW_HEIGHT)
	{
		i = 0;
		while(i < data->img.line_len)
		{
			if(j * i % 2 == 0)
				my_pixel_put(&data->img, i, j, GREEN_PIXEL);
			else
				my_pixel_put(&data->img, i, j, RED_PIXEL);
			i++;
		}
		j++;
	}
	// x = ((px - 100) / 100) * 2;
	// y = ((100 - py) / 100) * 2;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
