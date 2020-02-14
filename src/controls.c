/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:00:02 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/13 18:10:04 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mouse(int keycode, int x, int y, t_scene *s)
{
	if (keycode == 4 || keycode == 5)
	{
		s->x_c += (x - s->move_x) / ((WIDTH / 4) * s->zoom);
		s->y_c += (y - s->move_y) / ((WIDTH / 4) * s->zoom);
		s->move_x = x;
		s->move_y = y;
		if (keycode == 5)
			s->zoom *= 1 / 1.1;
		else if (keycode == 4)
			s->zoom *= 1.1;
		s->intr = WIDTH / 4.0 * s->zoom;
	}
	set_default(s);
	set_threads(s);
	return (0);
}

static int	mouse_move(int x, int y, t_scene *s)
{
	if (s->help == 0 || s->freeze == 1)
		return (0);
	s->c_re = (((float)x - WIDTH) / (WIDTH / 2)) + 1;
	s->c_im = (((float)y - WIDTH) / (WIDTH / 2)) + 1;
	set_threads(s);
	return (0);
}

void		manage_keys(t_scene *s)
{
	mlx_hook(s->win_ptr, 2, 0, key_press, s);
	mlx_hook(s->win_ptr, 4, 0, mouse, s);
	if (s->scheme == 1 && s->freeze == 0)
		mlx_hook(s->win_ptr, 6, 0, mouse_move, s);
}
