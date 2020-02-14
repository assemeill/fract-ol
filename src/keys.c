/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:40:47 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/13 18:36:47 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	freeze_julia(t_scene *s)
{
	if (s->freeze == 0)
		s->freeze = 1;
	else
		s->freeze = 0;
}

static void	help(t_scene *s)
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

static void	change_color(t_scene *s)
{
	if (s->color == 0)
	{
	//	s->r = 30;
	//	s->b = 10;
	//	s->g = -8;
		s->color = 1;
	}
	else if (s->color == 1)
	{
	//	s->r = 0;
	//	s->b = -150;
	//	s->g = -9;
		s->color = 2;
	}
	else if (s->color == 2)
	{
	//	s->r = -;
	//	s->b = 10;
	//	s->g = -9;
		s->color = 0;
	}	
	set_threads(s);
}

static void	key_move(int keycode, t_scene *s)
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

static void	key_zoom(int keycode, t_scene *s)
{
	if (keycode == 78 || keycode == 27)
		s->zoom *= 1 / 1.1;
	else if (keycode == 69 || keycode == 24)
		s->zoom *= 1.1;
	s->intr = WIDTH / 4.0 * s->zoom;
	set_threads(s);
}

int			key_press(int keycode, t_scene *s)
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
		exit(0);
	return (0);
}
