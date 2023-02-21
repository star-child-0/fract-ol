/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:15:54 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/20 19:17:31 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* int	ft_draw_pixels(t_data *data)
{
	int	i = 1900;
	int	j = 1000;
	while (data->win_ptr && i > 0)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, (i / 2), (j / 2), RED_PIXEL);
		i--;
		j--;
	}
	int	c = 1900;
	int	x = 1000;
	while (data->win_ptr && c > 0)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, c, (x / 2), GREEN_PIXEL);
		c--;
		x++;
	}
	int	b = 1900;
	int	a = 1000;
	while (data->win_ptr && a > 0)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, b / 2, a, BLUE_PIXEL);
		b++;
		a--;
	}
	return (0);
} */

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int draw(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	my_pixel_put(&data->img, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}