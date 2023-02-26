/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:49:57 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/25 17:12:01 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"fract-ol");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_key_hook(data.win_ptr, &hook_handler, &data);
	mlx_mouse_hook(data.win_ptr, &hook_handler, &data);
	mlx_hook(data.win_ptr, 17, 1L<<17, &hook_close_handler, &data);
	draw_handle(&data);
	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
