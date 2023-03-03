/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:02:42 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/28 17:31:28 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MLX_ERROR -1
# define MAX_ITER 100
//# define RED_PIXEL 0xFF0000
//# define GREEN_PIXEL 0xFF00

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_coords
{
	float	x;
	int	px;
	float	y;
	int	py;
}	t_coords;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		color;
	double	zoom;
	t_img	img;
	t_coords coord;
}	t_data;

void	my_pixel_put(t_data *data);

#endif
