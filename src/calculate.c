/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:18:05 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/05 17:23:23 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_scene *s)
{
	int		n;
	double	x_new;
	double	x_tmp;
	double	y_tmp;

	s->i = 0;
	x_new = 0;
	n = 0;
	x_tmp = s->x_min;
	y_tmp = s->y_min;
	while (y_tmp < s->y_max)
	{
		while (x_tmp < s->x_max)
		{
			s->c_re = (x_tmp - WIDTH/2.0)*(4.0*s->zoom)/WIDTH;
			s->c_im = (y_tmp - HEIGHT/2.0)*(4.0*s->zoom)/WIDTH;
			while (s->x * s->x + s->y * s->y < 4 && n++ < 1000)
			{
				x_new = s->x * s->x - s->y * s->y + s->c_re;
				s->y = 2 * s->x * s->y + s->c_im;
				s->x = x_new;
			}
			get_color(n, s);
			s->i++;
			x_tmp++;
			s->x = 0;
			s->y = 0;
			n = 0;
		}
		x_tmp = s->x_min;
		y_tmp++;
	}
}

/*
void	mandelbrot(t_scene *s)
{
	int		n;
	double	x_new;	

	s->i = 0;
	x_new = 0;
	n = 0;
	while (s->row < HEIGHT)
	{
		while (s->col < WIDTH)
		{
			s->c_re = (s->col - WIDTH/2.0)*(4.0*s->zoom)/WIDTH;
			s->c_im = (s->row - HEIGHT/2.0)*(4.0*s->zoom)/WIDTH;
			while (s->x * s->x + s->y * s->y < 4 && n++ < 1000)
			{
				x_new = s->x * s->x - s->y * s->y + s->c_re;
				s->y = 2 * s->x * s->y + s->c_im;
				s->x = x_new;
			}
			get_color(n, s);
			s->i++;
			s->col++;
			s->x = 0;
			s->y = 0;
			n = 0;
		}
		s->col = 0;
		s->row++;
	}
}
*/
void	julia(t_scene *s)
{
	int		n;	
	double	x_new;

	s->i = 0;
	x_new = 0;
	n = 0;
	s->x = (s->col - WIDTH/2.0)*(4.0*s->zoom)/WIDTH;
	s->y = (s->row - HEIGHT/2.0)*(4.0*s->zoom)/WIDTH;
	while (s->row < HEIGHT)
	{
		while (s->col < WIDTH)
		{
			while (s->x * s->x + s->y * s->y < 16 && n++ < 1000)
			{
				x_new = s->x * s->x - s->y * s->y;
				s->y = 2 * s->x * s->y + 0.156;
				s->x = x_new - 0.8;
			}
			s->x = (s->col - WIDTH/2.0)*(4.0*s->zoom)/WIDTH;
			s->y = (s->row - HEIGHT/2.0)*(4.0*s->zoom)/WIDTH;
			get_color(n, s);
			s->i++;
			s->col++;
			n = 0;
		}
		s->col = 0;
		s->row++;
	}
}

void	tricorn(t_scene *s)
{
	int		n;	
	double	x_new;

	x_new = 0;
	n = 0;
	s->i = 0;
	s->x = (s->col - WIDTH/2.0)*(4.0*s->zoom)/WIDTH;
	s->y = (s->row - HEIGHT/2.0)*(4.0*s->zoom)/WIDTH;
	s->c_re = s->x;
	s->c_im = s->y;
	while (s->row < HEIGHT)
	{
		while (s->col < WIDTH)
		{
			while (s->x * s->x + s->y * s->y < 4 && n++ < 1000)
			{
				x_new = s->x * s->x - s->y * s->y + s->c_re;
				s->y = -2 * s->x * s->y + s->c_im;
				s->x = x_new;
			}
			s->x = (s->col - WIDTH/2.0)*(4.0*s->zoom)/WIDTH;
			s->y = (s->row - HEIGHT/2.0)*(4.0*s->zoom)/WIDTH;
			s->c_re = s->x;
			s->c_im = s->y;
			get_color(n, s);
			s->i++;
			s->col++;
			n = 0;
		}
		s->col = 0;
		s->row++;
	}
}

void	burningship(t_scene *s)
{
	int		n;	
	double	x_new;

	x_new = 0;
	n = 0;
	s->i = 0;
	s->x = (s->col - WIDTH/2.0)*(4.0*s->zoom)/WIDTH;
	s->y = (s->row - HEIGHT/2.0)*(4.0*s->zoom)/WIDTH;
	s->c_re = s->x;
	s->c_im = s->y;
	while (s->row < HEIGHT)
	{
		while (s->col < WIDTH)
		{
			while (s->x * s->x + s->y * s->y < 4 && n++ < 1000)
			{
				x_new = s->x * s->x - s->y * s->y + s->c_re;
				s->y = ft_abs(2 * s->x * s->y + s->c_im);
				s->x = ft_abs(x_new);
			}
			s->x = (s->col - WIDTH/2.0)*(4.0*s->zoom)/WIDTH;
			s->y = (s->row - HEIGHT/2.0)*(4.0*s->zoom)/WIDTH;
			s->c_re = s->x;
			s->c_im = s->y;
			get_color(n, s);
			s->i++;
			s->col++;
			n = 0;
		}
		s->col = 0;
		s->row++;
	}
}
