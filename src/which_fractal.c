/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:23:29 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/17 19:29:12 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	which_fractal(char *fractal)
{
	if (!ft_strncmp(fractal, "mandelbrot", ft_strlen(fractal)))
		return (1);
	else if (!ft_strncmp(fractal, "julia", ft_strlen(fractal)))
		return (2);
	else if (!ft_strncmp(fractal, "burningship", ft_strlen(fractal)))
		return (3);
	return (0);
}
