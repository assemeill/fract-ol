/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:18:05 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/12 16:11:07 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_scene *s)
{
	int		n;
	float	x_new;

	x_new = 0;
	n = 0;
	s->c_re = s->x;
	s->c_im = s->y;
	s->x = 0;
	s->y = 0;
	while (s->x * s->x + s->y * s->y < 4 && n++ < 200)
	{
		x_new = s->x * s->x - s->y * s->y + s->c_re;
		s->y = 2 * s->x * s->y + s->c_im;
		s->x = x_new;
	}
	get_color(n, s);
}

void	julia(t_scene *s)
{
	int		n;
	float	x_new;

	x_new = 0;
	n = 0;
	while (s->x * s->x + s->y * s->y < 16 && n++ < 200)
	{
		x_new = s->x * s->x - s->y * s->y;
		s->y = 2 * s->x * s->y + s->c_im;
		s->x = x_new - s->c_re;
	}
	get_color(n, s);
}

void	tricorn(t_scene *s)
{
	int		n;
	float	x_new;

	x_new = 0;
	n = 0;
	s->c_re = s->x;
	s->c_im = s->y;
	while (s->x * s->x + s->y * s->y < 16 && n++ < 200)
	{
		x_new = s->x * s->x - s->y * s->y + s->c_re;
		s->y = -2 * s->x * s->y + s->c_im;
		s->x = x_new;
	}
	get_color(n, s);
}

void	burningship(t_scene *s)
{
	int		n;
	float	x_new;

	n = 0;
	s->c_re = s->x;
	s->c_im = s->y;
	while (s->x * s->x + s->y * s->y < 4 && n++ < 200)
	{
		x_new = s->x * s->x - s->y * s->y + s->c_re;
		s->y = ft_abs(2 * s->x * s->y + s->c_im);
		s->x = ft_abs(x_new);
	}
	get_color(n, s);
}
