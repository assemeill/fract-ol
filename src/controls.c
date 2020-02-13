/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:00:02 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/12 17:41:02 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int keycode, t_scene *s)
{
	if (keycode == 69 || keycode == 78 || keycode == 24 || keycode == 27)
		key_zoom(keycode, s);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		key_move(keycode, s);
	if (keycode == 4)
		help(s);
	if (keycode == 53)
		exit(0);
	return (0);
}

void	help(t_scene *s)
{
	if (s->help == 1)
		s->help = 0;
	else
		s->help = 1;
	if (s->help == 1)
		set_help(s);
	else
		set_threads(s);	
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
		s->zoom *= 0.8;
	else if (keycode == 69 || keycode == 24)
		s->zoom /= 0.9;
//	s->intr = WIDTH / 4.0 * s->zoom;
	set_threads(s);
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
			s->zoom *= 1/1.1;
		else if (keycode == 4)
			s->zoom *= 1.1;
		s->intr = WIDTH / 4.0 * s->zoom;
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
