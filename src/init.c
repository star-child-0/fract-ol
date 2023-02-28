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
	mlx_loop(fractal->mlx);
	return (0);
}

int	window_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!(fractal->mlx))
		ft_printf("Error\n");
	fractal->window = mlx_new_window(fractal->mlx,
			WIDTH, HEIGHT, "fract-ol");
	if (!(fractal->window))
		ft_printf("Error\n");
	return (0);
}
