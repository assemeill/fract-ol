/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:00:02 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/30 16:00:51 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int keycode, t_coord *t)
{ 
	if (keycode == 69)// || keycode == 78 || keycode == 24 || keycode == 27)
		key_zoom(keycode, t);
	if (keycode == 53)
		exit(0);
//		ft_close(t->win_ptr, t);
//	if (keycode == 49 || keycode == 48)
//		change_pr(keycode, t);
//	if (keycode >= 123 && keycode <= 126)
//		key_move(keycode, t);
	return (0);
}

void	key_zoom(int keycode, t_coord *t)
{
	if (keycode == 69)
	{
		t->zoom *= 0.9;
		julia(t);
		put_image(t);
	}
}

void	manage_keys(t_coord *t)
{
	mlx_hook(t->win_ptr, 2, 0, key_press, t);
//	mlx_hook(t->win_ptr, 17, 0, ft_close, t);
}
