/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:59:56 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/03 15:36:25 by cscelfo          ###   ########.fr       */
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

# define WIN_WIDTH 600
# define WIN_HEIGHT 600
# define MAX_ITER 150

typedef struct  s_complex
{
    float      re; // real
	float	   re_sq; // real squared
    float      im; // imaginary
	float	   im_sq; // imaginary squared
}               t_complex;

typedef struct s_coords
{
	float	px;
	float	py;
	t_complex	c;
	t_complex	z;
	float	tmp;
	int		iter;
	int		max_iter;
}	t_coords;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*fractal;
	float		zoom;
	int 		color;
	int			move_x;
	int			move_y;
	float       x_min;
	float       x_max;
	float       y_min;
	float       y_max;
	int			mouse_x;
	int			mouse_y;
	int         screen_width;
	int         screen_height;
	int		    win_pos_x;
	int		    win_pos_y;
	t_img		img;
	t_coords	coord;
}	t_data;

/*Args*/
int		valid_args(int argc, char **argv);
/*Init*/
int		hooks_init(t_data *data);
int		window_init(t_data *data);
void	mlx_set_window_position(void *mlx_ptr, void *win_ptr, int x, int y);
int		get_small_side();
/*Hooks*/
//int		hook_handler(int keycode, t_data *data);
int		key_handler(int keycode, t_data *data);
int		mouse_handler(int keycode, t_data *data);
/*Draw*/
void	draw_handler(t_data *data);
int		equation(t_data *data);
void		equation2(t_data *data);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	draw(t_data *data);
void	window_labels(t_data *data);
/*Errors*/
int		error_msg(void);
/*End*/
int		end_fractal(t_data *data);

#endif
