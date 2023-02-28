/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:43:51 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/28 21:39:52 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_args(char **argv)
{
	int	x;
	int	y;

	x = ft_atof(argv[2]);
	y = ft_atof(argv[3]);
	if (x > -2 && x < 2 && y > -2 && y < 2)
		return (1);
	return (0);
}

int	valid_args(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1]))
			|| !ft_strncmp(argv[1], "burningship", ft_strlen(argv[1])))
			return (1);
	}
	else if (argc == 4)
	{
		if (!ft_strncmp(argv[1], "julia", ft_strlen(argv[1]))
			&& julia_args(argv))
			return (1);
	}
	else
		error_msg();
	return (0);
}
