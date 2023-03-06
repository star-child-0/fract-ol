/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:09:55 by gmattei           #+#    #+#             */
/*   Updated: 2023/03/06 19:32:43 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	*pixel;

	pixel = (int *)&data->img.addr[y * data->img.line_len + x
		*(data->img.bpp / 8)];
	*pixel = color;
}

void	draw(t_data *data)
{
	if(data->mouse_x > WIN_WIDTH)
		data->mouse_x = WIN_WIDTH;
	if(data->mouse_y > WIN_HEIGHT)
		data->mouse_y = WIN_HEIGHT;
	if(data->mouse_y < 0)
		data->mouse_y = 0;
	equation(data);
	ft_printf("mouse_x: %d, mouse_y: %d, move_x: %d, move_y: %d\n", data->mouse_x, data->mouse_y, data->move_x, data->move_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	window_labels(data);
}

void	window_labels(t_data *data)
{
	int color;

	color = 0xffffff;
	if(data->color >= color - 0x080808 && data->color <= 0x080808)
		color = 0x000000;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 40, color, "Arrow keys to move around");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 35, 60, color, "'C' to change the color range");
}
