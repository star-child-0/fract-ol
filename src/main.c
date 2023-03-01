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
	t_fractal	*fractal;

	if (!valid_args(argc, argv))
		error_msg();
	else
	{
		fractal = (t_fractal *)malloc(sizeof(t_fractal));
		window_init(fractal);
		hooks_init(fractal);
		free(fractal);
	}
	return (0);
}
