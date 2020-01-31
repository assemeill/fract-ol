/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:18:05 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/30 13:55:02 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_coord *t)
{
	int		n;	
	double	col;
	double	row;
	double	c_re;
	double	c_im;
	double	x;
	double	x_new;
	double	y;

	t->i = 0;
	row = 0;
	col = 0;
	x = 0;
	x_new = 0;
	y = 0;
	n = 0;
	while (row < t->height)
	{
		while (col < t->width)
		{
			c_re = (col - t->width/2.0)*4.0/t->width;
			c_im = (row - t->height/2.0)*4.0/t->width;
			while (x*x + y*y < 4 && n++ <= 1000)
			{
				x_new = x*x - y*y + c_re;
				y = 2*x*y + c_im;
				x = x_new;
			}
			set_color(n, t);
			t->i++;
			col++;
			x = 0;
			y = 0;
			n = 0;
		}
		col = 0;
		row++;
	}
}

void	julia(t_coord *t)
{
	int		n;	
	double	col;
	double	row;
	double	x;
	double	x_new;
	double	y;

	t->i = 0;
	row = 0;
	col = 0;
	x_new = 0;
	n = 0;
	x = (col - t->width/2.0)*(4.0*t->zoom)/t->width;
	y = (row - t->height/2.0)*(4.0*t->zoom)/t->width;
	while (row < t->height)
	{
		while (col < t->width)
		{
			while (x*x + y*y < 16 && n++ < 1000)
			{
				x_new = x*x - y*y;
				y = 2*x*y + 0.156;
				x = x_new - 0.8;
			}
			x = (col - t->width/2.0)*(4.0*t->zoom)/t->width;
			y = (row - t->height/2.0)*(4.0*t->zoom)/t->width;
			set_color(n, t);
			t->i++;
			col++;
			n = 0;
		}
		col = 0;
		row++;
	}
}

void	tricorn(t_coord *t)
{
	int		n;	
	double	col;
	double	row;
	double	c_re;
	double	c_im;
	double	x;
	double	x_new;
	double	y;

	row = 0;
	col = 0;
	x_new = 0;
	n = 0;
	x = (col - t->width/2.0)*4.0/t->width;
	y = (row - t->height/2.0)*4.0/t->width;
	c_re = x;
	c_im = y;
	while (row < t->height)
	{
		while (col < t->width)
		{
			while (x*x + y*y < 4 && n++ < 200)
			{
				x_new = x*x - y*y + c_re;
				y = -2*x*y + c_im;
				x = x_new;
			}
			x = (col - t->width/2.0)*4.0/t->width;
			y = (row - t->height/2.0)*4.0/t->width;
			c_re = x;
			c_im = y;
			set_color(n, t);
			t->i++;
			col++;
			n = 0;
		}
		col = 0;
		row++;
	}
}

void	burningship(t_coord *t)
{
	int		n;	
	double	col;
	double	row;
	double	c_re;
	double	c_im;
	double	x;
	double	x_new;
	double	y;

	row = 0;
	col = 0;
	x_new = 0;
	n = 0;
	x = (col - t->width/2.0)*4.0/t->width;
	y = (row - t->height/2.0)*4.0/t->width;
	c_re = x;
	c_im = y;
	while (row < t->height)
	{
		while (col < t->width)
		{
			while (x*x + y*y < 4 && n++ < 200)
			{
				x_new = x*x - y*y + c_re;
				y = ft_abs(2*x*y + c_im);
				x = ft_abs(x_new);
			}
			x = (col - t->width/2.0)*4.0/t->width;
			y = (row - t->height/2.0)*4.0/t->width;
			c_re = x;
			c_im = y;
			set_color(n, t);
			t->i++;
			col++;
			n = 0;
		}
		col = 0;
		row++;
	}
}
