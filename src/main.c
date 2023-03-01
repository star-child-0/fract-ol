/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:00:00 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/28 21:37:32 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	printf("scroll up");
	t_fractal	*fractal;

	if (!valid_args(argc, argv))
		error_msg();
	else
	{
		fractal = (t_fractal *)malloc(sizeof(t_fractal));
		window_init(fractal);
		//draw
		hooks_init(fractal);
		end_fractal(fractal);
	}
	return (0);
}
