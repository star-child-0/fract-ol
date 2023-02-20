/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:49:57 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/20 18:00:39 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fract-ol");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
//	mlx_loop_hook(data.mlx_ptr, &ft_handle_nothing, &data);
	mlx_loop_hook(data.mlx_ptr, &ft_draw_pixels, &data);
	mlx_hook(data.win_ptr, 2, 1L<<0, ft_close, &data);
	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
