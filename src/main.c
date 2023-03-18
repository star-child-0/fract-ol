/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:00:00 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/18 18:11:12 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->fractal = which_fractal(argv[1]);
	if (!valid_args(argc, argv, data))
		error_msg();
	else
	{
		window_init(data);
		draw_handler(data);
		hooks_init(data);
	}
	return (0);
}
