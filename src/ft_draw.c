/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:15:54 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/25 17:10:40 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	ft_blue(t_data *data, int iterations, float px, float py)
{
	int			blue;

	blue = 0x0000FF;
	if (iterations < MAX_ITER)
		my_pixel_put(&data->img, px, py, blue + iterations * 5);
}

// Draw the fractal
void	draw(t_data *data)
{
	int			iterations;
	int			small_side;
	t_coords	coord;

	coord.px = 0;
	coord.py = 0;
	iterations = 0;
	small_side = WINDOW_HEIGHT;
	if (WINDOW_WIDTH < WINDOW_HEIGHT)
		small_side = WINDOW_WIDTH;
	while (coord.px <= WINDOW_WIDTH)
	{
		coord.py = 0;
		while (coord.py <= small_side)
		{
			coord.x = ((coord.px - (small_side / 2)) / (small_side / 2)) * 2;
			coord.y = (((small_side / 2) - coord.py) / (small_side / 2)) * 2;
			iterations = ft_pass(&coord);
			ft_blue(data, iterations, coord.px, coord.py);
			coord.py++;
		}
		coord.px++;
	}
}

// Draw handler
int	draw_handle(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	return (0);
}