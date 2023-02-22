/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_equation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:39:20 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/22 19:03:20 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Returns the number of iterations before a coordinate escapes the
// mandelbrot set
int	ft_pass(t_coords *coord)
{
	int		i;
	float	zx;
	float	zy;

	if (pow(coord->x, 2) + pow(coord->y, 2) > 4)
		return (1);
	i = 2;
	coord->cx = pow(coord->x, 2) - pow(coord->y, 2) + coord->x;
	coord->cy = (2 * coord->x * coord->y) + coord->y;
	while (sqrt(pow(coord->cx, 2) + pow(coord->cy, 2)) < 2 && ++i
		&& i <= MAX_ITER)
	{
		zx = pow(coord->cx, 2) - pow(coord->cy, 2) + coord->x;
		zy = (2 * coord->cx * coord->cy) + coord->y;
		coord->cx = zx;
		coord->cy = zy;
	}
	return (i);
}
