/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:00:02 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/14 14:05:22 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse(int keycode, int x, int y, t_scene *s)
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

int		key_press(int keycode, t_scene *s)
{
	if (keycode == 69 || keycode == 78 || keycode == 24 || keycode == 27)
		key_zoom(keycode, s);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		key_move(keycode, s);
	if (keycode == 49)
		change_color(s);
	if (keycode == 4)
		help(s);
	if (keycode == 3)
		freeze_julia(s);
	if (keycode == 53)
		close_fr(s);
	return (0);
}

int		close_fr(t_scene *s)
{
	free(s);
	exit(0);
}

void	manage_keys(t_scene *s)
{
	mlx_hook(s->win_ptr, 2, 0, key_press, s);
	mlx_hook(s->win_ptr, 4, 0, mouse, s);
	if (s->scheme == 1 && s->freeze == 0)
		mlx_hook(s->win_ptr, 6, 0, mouse_move, s);
}
