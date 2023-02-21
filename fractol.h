/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:02:42 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/21 14:16:23 by cscelfo          ###   ########.fr       */
/*   Updated: 2023/02/20 19:41:08 by anvannin         ###   ########.fr       */
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
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0x0000FF 

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_coords
{
	float	x;
	float	y;
}	t_coords;

int	ft_close(int keycode, t_data *data);
//int	ft_handle_nothing(void *data);
int	ft_draw_pixels(t_data *data);

#endif
