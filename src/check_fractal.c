/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:45:18 by cscelfo           #+#    #+#             */
/*   Updated: 2023/03/06 20:12:24 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_fractal(char **argv, t_data *data)
{
	if (!ft_strncmp(data->fractal, "mandelbrot", ft_strlen(data->fractal)))
	{
		data->coord.z.re = 0;
		data->coord.z.im = 0;
		data->coord.z.re_sq = 0;
		data->coord.z.im_sq = 0;
	}
	else if (!ft_strncmp(data->fractal, "julia", ft_strlen(data->fractal)))
	{
		data->coord.z.re = ft_atof(argv[2]);
		data->coord.z.im = ft_atof(argv[3]);
		data->coord.z.re_sq = data->coord.z.re * data->coord.z.re;
		data->coord.z.im_sq = data->coord.z.im * data->coord.z.im;
	}
/*	else
	{
	
	}*/
	return ;
}
