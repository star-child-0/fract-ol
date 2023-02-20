/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:09:52 by cscelfo           #+#    #+#             */
/*   Updated: 2023/02/20 18:01:05 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
int	ft_handle_nothing()
{
	return (0);
}
*/
int	ft_close(int keycode, t_data *data)
{
	if (keycode == XK_Escape) //Press ESC to close the window
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_printf("Keypress: %d\n", keycode);
	return (0);
}
