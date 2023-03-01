/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:12:36 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/28 21:47:03 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hooks_init(t_data *data)
{
	mlx_key_hook(data->win_ptr, &hook_handler, &data);
	mlx_mouse_hook(data->win_ptr, &hook_handler, &data);
	mlx_hook(data->win_ptr, 17, 1L<<17, (&end_data), &data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	window_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!(data->mlx_ptr))
		ft_printf("Error\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "fract-ol");
	if (!(data->win_ptr))
		ft_printf("Error\n");
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!(data->img.mlx_img))
		ft_printf("Error\n");
	data->img.addr = mlx_get_data_addr(data->img.mlx_img,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	return (0);
}

int end_data(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	data->img.mlx_img = NULL;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	data->mlx_ptr = NULL;
	free(data->mlx_ptr);
	return(0);
}

void draw_handler(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->color = 0x080808;
	data->zoom = MAX_ITER;
	equation(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img.mlx_img, 0, 0);
}