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

int	ft_draw_pixels(t_data *data)
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
}
