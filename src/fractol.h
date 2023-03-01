/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:59:56 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/28 21:28:44 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 250

typedef struct s_float_coords
{

}	t_coords;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_coords coord;
	//int add_px;
	//int add_py;
	//int color;
	//float zoom;
}	t_fractal;

int		valid_args(int argc, char **argv);
int		hooks_init(t_fractal *fractal);
int		window_init(t_fractal *fractal);
int		error_msg(void);
void	end_fractal(t_fractal *fractal);

#endif
