/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:00:00 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/28 21:37:32 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	printf("|---|\n");
	t_data	*data;

	if (!valid_args(argc, argv))
		error_msg();
	else
	{
		data = (t_data *)malloc(sizeof(t_data));
		window_init(data);
		//draw
		hooks_init(data);
		end_data(data);
	}
	return (0);
}
