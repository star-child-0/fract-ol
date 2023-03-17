/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:43:51 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/17 19:40:51 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_args(char **argv)
{
	int	x;
	int	y;

	x = atof(argv[2]);
	y = atof(argv[3]);
	if (x > -2 && x < 2 && y > -2 && y < 2)
		return (1);
	return (0);
}

int	valid_args(int argc, char **argv)
{
	int	which;

	which = which_fractal(argv[1]);
	if (argc == 2)
	{
		if (which >= 2 && which <= 3)
			return (1);
	}
	else if (argc == 4)
	{
		if (which == 2 && julia_args(argv))
			return (1);
	}
	else
		error_msg();
	return (0);
}
