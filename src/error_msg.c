/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:27:18 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/28 21:46:30 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error_msg(void)
{
	ft_printf("mandelbrot/burningship: ./fractol fractal\n");
	ft_printf("julia: ./fractol julia x y coordinates (x and y");
	ft_printf("being complex numbers between -2.000 and 2.000)\n");
	ft_printf("Available fractals: mandelbrot, julia, burningship\n");
	return (0);
}
