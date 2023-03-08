/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:00:00 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/03 18:39:57 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (!valid_args(argc, argv))
		error_msg();
	else
	{
		data = (t_data *)malloc(sizeof(t_data));
		data->fractal = argv[1];
		window_init(data);
		draw_handler(data);
		hooks_init(data);
	}
	return (0);
}
