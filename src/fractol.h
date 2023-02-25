/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:02:42 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/25 17:11:03 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

//# define WINDOW_WIDTH 1920
//# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define MLX_ERROR -1
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define MAX_ITER 250
# define BLUE_PIXEL 0x0000FF

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

int	key_hook_handler(int keycode, t_data *data);
int	hook_close_handler(t_data *data);
//int	ft_handle_nothing(void *data);
int	pass(float x, float y);
int	ft_draw_pixels(t_data *data);
int		key_hook_handler(int keycode, t_data *data);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	draw(t_data *data, int x, int y);
int		draw_handle(t_data *data);
int		ft_pass(t_coords *coord);

#endif