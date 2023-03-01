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

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MAX_ITER 250

typedef struct s_coords
{
	float x;
	float y;
	float cr;
	float ci;
	float zr;
	float zi;
	float tmp;
	int iter;
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
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_coords coord;
	//int add_px;
	//int add_py;
	//int color;
	float zoom;
}	t_data;

/*Args*/
int		valid_args(int argc, char **argv);
/*Init*/
int		hooks_init(t_data *data);
int		window_init(t_data *data);
/*Hooks*/
int		hook_handler(int keycode, t_data *data);
int		key_handler(int keycode, t_data *data);
int		mouse_handler(int keycode);
/*Errors*/
int		error_msg(void);
/*End*/
int	end_data(t_data *data);

#endif
