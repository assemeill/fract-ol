/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:00:02 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/31 21:06:29 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int keycode, t_scene *s)
{ 
	if (keycode == 69)// || keycode == 78 || keycode == 24 || keycode == 27)
		key_zoom(keycode, s);
	if (keycode == 53)
		exit(0);
//		ft_close(t->win_ptr, t);
//	if (keycode == 49 || keycode == 48)
//		change_pr(keycode, t);
//	if (keycode >= 123 && keycode <= 126)
//		key_move(keycode, t);
	return (0);
}

void	key_zoom(int keycode, t_scene *s)
{
	if (keycode == 69)
	{
		s->zoom *= 0.9;
//		call(
		put_image(s);
	}
}

void	manage_keys(t_scene *s)
{
	mlx_hook(s->win_ptr, 2, 0, key_press, s);
//	mlx_hook(t->win_ptr, 17, 0, ft_close, t);
}
