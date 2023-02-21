/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:39:20 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/21 16:59:18 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// this is to be removed
#include <math.h>
#include <stdio.h>

int	pass(float x, float y)
{
	int	i;
	float	cx;
	float	cy;
	float zx;
	float zy;

	if (pow(x, 2) + pow(y, 2) > 4) // first pass
		return (1);
	i = 2;
	cx = pow(x, 2) - pow(y, 2) + x;
	cy = (2 * x * y) + y;
	while (sqrt(pow(cx, 2) + pow(cy, 2)) < 2 && ++i) // second pass or more
	{
		zx = pow(cx, 2) - pow(cy, 2) + x;
		zy = (2 * cx * cy) + y;
		cx = zx;
		cy = zy;
	}
	return (i);
}
/*
int	main(void)
{
// 	printf("(-2, 1): %d steps\n", pass(-2, 1));
//	printf("(-1.5, 1): %d steps\n", pass(-1.5, 1));
// 	printf("(-1, 1): %d steps\n", pass(-1, 1));
//	printf("\n(0, 0.6357): %d steps\n", pass(0, 0.6357)); 8960 steps
// 	printf("(0, 2): %d steps\n", pass(0, 2));
 	printf("\n(-0.5500, 0.4800): %d steps\n", pass(-0.5500, 0.4800));
}*/
