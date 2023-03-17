/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:12:36 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/17 19:04:55 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hooks_init(t_data *data)
{
	mlx_do_key_autorepeaton(data->mlx_ptr);
	mlx_hook(data->win_ptr, 2, 1l << 0, &key_handler, data);
	mlx_mouse_hook(data->win_ptr, &mouse_handler, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, end_fractal, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	window_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		ft_printf("An error has occured! Please fix your code and try again!\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "fract-ol");
	if (!(data->win_ptr))
		ft_printf("An error has occured! Please fix your code and try again!\n");
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!(data->img.mlx_img))
		ft_printf("An error has occured! Please fix your code and try again!\n");
	data->img.addr = mlx_get_data_addr(data->img.mlx_img,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	return (0);
}

int	end_fractal(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	data->win_ptr = NULL;
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	free(data);
	exit(0);
	return (0);
}

void	draw_handler(t_data *data)
{
	data->x_max = 2;
	data->x_min = -2;
	data->y_max = 2;
	data->y_min = -2;
	data->move_x = 0;
	data->move_y = 0;
	data->mouse_x = 0;
	data->mouse_y = 0;
	data->small_side = get_small_side();
	data->zoom = 1;
	data->coord.max_iter = MAX_ITER;
	data->color = 0xBB00AA;
	draw(data);
}

int	get_small_side(void)
{
	if (WIN_WIDTH < WIN_HEIGHT)
		return (WIN_WIDTH);
	else
		return (WIN_HEIGHT);
	return (0);
}
