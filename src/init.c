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

int	hooks_init(t_fractal *fractal)
{
	mlx_loop(fractal->mlx_ptr);
	return (0);
}

int	window_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	ft_printf("|---|\n");
	if (!(fractal->mlx_ptr))
		ft_printf("Error\n");
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr,
			WIDTH, HEIGHT, "fract-ol");
	if (!(fractal->win_ptr))
		ft_printf("Error\n");
	return (0);
}

void end_fractal(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	fractal->win_ptr = NULL;
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
}