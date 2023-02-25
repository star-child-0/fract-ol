/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:15:54 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/25 18:25:03 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

/* void color_shift(int x, int y)
{

} */

// Draw the fractal
void	draw(t_data *data, int x, int y)
{
	t_coords	coord;
	int			iterations;
	int			small_side;
	int color = 0x0000ff;

	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	iterations = 0;
	small_side = WINDOW_HEIGHT;
	if (WINDOW_WIDTH < WINDOW_HEIGHT)
		small_side = WINDOW_WIDTH;
	while (coord.px <= WINDOW_WIDTH)
	{
		coord.py = 0;
		while (coord.py <= small_side)
		{
			coord.x = (((coord.px + x) - (small_side / 2)) / (small_side / 2)) * 2;
			coord.y = (((small_side / 2) - (coord.py + y)) / (small_side / 2)) * 2;
			iterations = ft_mandelbrot_pass(&coord);
			if (iterations < MAX_ITER)
				my_pixel_put(&data->img, coord.px, coord.py, color + iterations * 5);
			coord.py++;
		}
		coord.px++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
}

// Draw handler
int	draw_handle(t_data *data)
{
	t_coords coord;
	if (data->win_ptr == NULL)
		return (1);
	coord.px = 0;
	draw(data, 0, 0);
	return (0);
}