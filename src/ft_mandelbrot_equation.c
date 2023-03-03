/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_equation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:39:20 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/28 18:22:27 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Returns the number of iterations before a coordinate escapes the
// mandelbrot set
int	ft_mandelbrot_pass(t_coords *coord)
{
	int		i;
	float	zx;
	float	zy;

	if (pow(coord->x, 2) + pow(coord->y, 2) > 4)
		return (1);
	i = 2;
	coord->cx = pow(coord->x, 2) - pow(coord->y, 2) + coord->x;
	coord->cy = (2 * coord->x * coord->y) + coord->y;
	//coord->cx = 0;
	//coord->cy = 0;
	while (pow(coord->cx, 2) + pow(coord->cy, 2) < 4 && i < MAX_ITER
	&& ++i)
	{
		zx = pow(coord->cx, 2) - pow(coord->cy, 2) + coord->x;
		zy = (2 * coord->cx * coord->cy) + coord->y;
		coord->cx = zx;
		coord->cy = zy;
	}
	return (i);
}

void	ft_julia(t_coords *coord)
{
	int	r;
	int	zx;
	int	tmpzx;
	int	zy;
	int	iter;

	iter = 0;
	r = sqrt(INT_MAX); // un numero veramente grande (non so se è giusto)
	while (coord->px < WINDOW_WIDTH)
	{
		coord->py = 0;
		while (coord->py < WINDOW_HEIGHT)
		{
			zx = pow(coord->cx, 2) - pow(coord->cy, 2) + coord->x;
			zy = (2 * coord->x * coord->y) + coord->y;
			while (pow(zx, 2) + pow(zy, 2) < pow(r, 2) && iter < MAX_ITER)
			{
				tmpzx = pow(zx, 2) - pow(zy, 2) + coord->x;
				zy = (2 * zx * zy) + coord->y;
				zx = tmpzx;
				iter++;
			}
			coord->py++;
		}
		coord->px++;
	}
}
