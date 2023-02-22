/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_equation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:39:20 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/22 17:26:52 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_pass(t_coords *coord)
{
	int	i;

	if (pow(coord->x, 2) + pow(coord->y, 2) > 4) // first pass
		return (1);
	i = 2;
	coord->cx = pow(coord->x, 2) - pow(coord->y, 2) + coord->x;
	coord->cy = (2 * coord->x * coord->y) + coord->y;
	while (sqrt(pow(coord->cx, 2) + pow(coord->cy, 2)) < 2 && ++i && i <= MAX_ITER) // second pass or more
	{
		coord->zx = pow(coord->cx, 2) - pow(coord->cy, 2) + coord->x;
		coord->zy = (2 * coord->cx * coord->cy) + coord->y;
		coord->cx = coord->zx;
		coord->cy = coord->zy;
	}
	return (i);
}
/*#include <math.h>
#include <stdio.h>

int	main(void)
{
// 	printf("(-2, 1): %d steps\n", pass(-2, 1));
//	printf("(-1.5, 1): %d steps\n", pass(-1.5, 1));
// 	printf("(-1, 1): %d steps\n", pass(-1, 1));
//	printf("\n(0, 0.6357): %d steps\n", pass(0, 0.6357)); 8960 steps
// 	printf("(0, 2): %d steps\n", pass(0, 2));
 	printf("\n(-0.5500, 0.4800): %d steps\n", pass(-0.5500, 0.4800));
}*/
// printf("x=[%f] | y=[%f] | coord->cx=[%f] | coord->cy=[%f] | iterations=[%d]\n\n", x, y, cx, cy, i);*/
