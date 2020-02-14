/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:40:47 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/14 13:53:48 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	freeze_julia(t_scene *s)
{
	if (s->freeze == 0)
		s->freeze = 1;
	else
		s->freeze = 0;
}

void	help(t_scene *s)
{
	if (s->help == 1)
	{
		s->help = 0;
		set_help(s);
	}
	else
	{
		s->help = 1;
		set_threads(s);
	}
}

void	change_color(t_scene *s)
{
	if (s->help == 1)
	{
		if (s->color == 0)
			s->color = 1;
		else if (s->color == 1)
			s->color = 2;
		else if (s->color == 2)
			s->color = 0;
		set_threads(s);
	}
}

void	key_move(int keycode, t_scene *s)
{
	if (keycode == 126)
		s->y_c += (1.1 - s->move_y) / ((WIDTH / 4) * s->zoom);
	if (keycode == 125)
		s->y_c -= (1.1 - s->move_y) / ((WIDTH / 4) * s->zoom);
	if (keycode == 123)
		s->x_c += (1.1 - s->move_x) / ((WIDTH / 4) * s->zoom);
	if (keycode == 124)
		s->x_c -= (1.1 - s->move_x) / ((WIDTH / 4) * s->zoom);
	set_threads(s);
}

void	key_zoom(int keycode, t_scene *s)
{
	if (keycode == 78 || keycode == 27)
		s->zoom *= 1 / 1.1;
	else if (keycode == 69 || keycode == 24)
		s->zoom *= 1.1;
	s->intr = WIDTH / 4.0 * s->zoom;
	set_threads(s);
}
