/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:59:56 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/18 18:13:04 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
//# include "../minilibx-linux/mlx_int.h"
# include <math.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_WIDTH 600
# define WIN_HEIGHT 600
# define MAX_ITER 150

// re		=	real
// re_sq	=	real squared
// im		=	imaginary
// im_sq	=	imaginary squared
typedef struct s_complex
{
	float		re;
	float		re_sq;
	float		im;
	float		im_sq;
}	t_complex;

typedef struct s_coords
{
	int			iter;
	int			max_iter;
	float		px;
	float		py;
	t_complex	c;
	t_complex	z;
}	t_coords;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/*
	fractal =	1 for mandelbrot
			2 for julia
			3 for burningship
*/
typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			fractal;
	int			small_side;
	long double	zoom;
	int			color;
	int			move_x;
	int			move_y;
	float		x_min;
	float		x_max;
	float		y_min;
	float		y_max;
	int			mouse_x;
	int			mouse_y;
	float		mouse_pos_x;
	float		mouse_pos_y;
	long double	zoom_decr;
	long double	zoom_incr;
	long double	new_zoom;
	long double	zoom_factor;
	t_img		img;
	t_coords	coord;
}	t_data;

/*Args*/
int		julia_args(char **argv, t_data *data);
int		valid_args(int argc, char **argv, t_data *data);

/* Which fractal */
int		which_fractal(char *fractal);

/*Init*/
int		hooks_init(t_data *data);
int		window_init(t_data *data);
void	mlx_set_window_position(void *mlx_ptr, void *win_ptr, int x, int y);
int		get_small_side(void);
/*Hooks*/
//int		hook_handler(int keycode, t_data *data);
int		key_handler(int keycode, t_data *data);
int		mouse_handler(int keycode, int x, int y, t_data *data);
/*Draw*/
void	draw_handler(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw(t_data *data);
void	window_labels(t_data *data);

/* Mandelbrot */
int		mandelbrot_equation(t_data *data);
void	mandelbrot_sequel(t_data *data);

/* Julia */
void	julia_equation_init(t_data *data);
int		julia_equation(t_data *data);
void	julia_sequel(t_data *data);

/*Errors*/
int		error_msg(void);
/*End*/
int		end_fractal(t_data *data);

#endif
