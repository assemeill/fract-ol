/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:00:02 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/11 21:01:35 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int keycode, t_scene *s)
{ 
	if (keycode == 69)// || keycode == 78 || keycode == 24 || keycode == 27)
		key_zoom(keycode, s);
	if (keycode == 53)
		exit(0);
	return (0);
}

void	key_zoom(int keycode, t_scene *s)
{
	if (keycode == 69)
	{
		s->zoom *= 0.8;
		set_default(s);
		set_threads(s);
	}
}

int		mouse(int keycode, int x, int y, t_scene *s)
{
	if (keycode == 4 || keycode == 5)
	{
		s->x_c += (x - s->move_x) / ((WIDTH / 4) * s->zoom);
		s->y_c += (y - s->move_y) / ((WIDTH / 4) * s->zoom);
		s->move_x = x;
		s->move_y = y;
		if (keycode == 5)
			s->zoom *= 0.8;
		else if (keycode == 4)
			s->zoom /= 0.9;
		s->intr = WIDTH/4.0*s->zoom;
	}
		set_default(s);
		set_threads(s);
	return (0);
}

int		mouse_move(int x, int y, t_scene *s)
{
	s->c_re = (((float)x - WIDTH) / (WIDTH / 2)) + 1;
	s->c_im = (((float)y - WIDTH) / (WIDTH / 2)) + 1;
	set_threads(s);
	return (0);
}

void	manage_keys(t_scene *s)
{
	mlx_hook(s->win_ptr, 2, 0, key_press, s);
	mlx_hook(s->win_ptr, 4, 0, mouse, s);
	if (s->scheme == 1)
		mlx_hook(s->win_ptr, 6, 0, mouse_move, s);
}
