/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:15:54 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/20 18:00:53 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_draw_pixels(t_data *data)
{
	if (data->win_ptr)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	return (0);
}
