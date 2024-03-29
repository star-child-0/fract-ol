/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:43:51 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/18 18:13:37 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_args(char **argv, t_data *data)
{
	float	x;
	float	y;

	x = atof(argv[2]);
	y = atof(argv[3]);
	if (x > -2 && x < 2 && y > -2 && y < 2)
	{
		data->coord.c.re = x;
		data->coord.c.im = y;
		return (1);
	}
	return (0);
}

int	valid_args(int argc, char **argv, t_data *data)
{
	if (argc == 2 && (data->fractal == 1 || data->fractal == 3))
		return (1);
	else if (argc == 4 && data->fractal == 2 && julia_args(argv, data))
		return (1);
	else
		error_msg();
	return (0);
}
