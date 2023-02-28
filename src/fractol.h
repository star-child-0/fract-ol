/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:02:42 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/27 17:59:55 by cscelfo          ###   ########.fr       */
/*   Updated: 2023/02/20 19:41:08 by anvannin         ###   ########.fr       */
/*   Updated: 2023/02/25 18:25:03 by anvannin         ###   ########.fr       */
/*   Updated: 2023/02/27 17:26:01 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>

//# define WINDOW_WIDTH 1920
//# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 1080
# define MLX_ERROR -1
# define MAX_ITER 50

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
	t_img	*img;
	int add_px;
	int add_py;
	int color;
	float zoom;
}	t_data;

typedef struct s_float_coords
{
	float	x;
	float	px;
	float	cx;
	float	y;
	float	py;
	float	cy;
}	t_coords;

int	hook_handler(int keycode, t_data *data);
int	hook_close_handler(t_data *data);
int	key_hook_handler(int keycode, t_data *data);
int	ft_draw_pixels(t_data *data);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	draw(t_data *data);
int		draw_handle(t_data *data);
int		ft_mandelbrot_pass(t_coords *coord);

#endif
