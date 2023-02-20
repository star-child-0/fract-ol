/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:39:20 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/20 21:10:18 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// this is to be removed
#include <math.h>

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

// gcc passes.c -lm to test
// int	main(void)
// {
// 	#include <stdio.h>
// 	printf("(-2, 1): %d steps\n", pass(-2, 1));
// 	printf("(-1.5, 1): %d steps\n", pass(-1.5, 1));
// 	printf("(-1, 1): %d steps\n", pass(-1, 1));
// }