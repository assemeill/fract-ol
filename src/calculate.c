/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:18:05 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/31 19:55:24 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_coord *c, t_scene *s)
{
	int		n;
	double	x_new;	

	c->i = 0;
	x_new = 0;
	n = 0;
	while (c->row < s->height)
	{
		while (c->col < s->width)
		{
			c->c_re = (c->col - s->width/2.0)*(4.0*s->zoom)/s->width;
			c->c_im = (c->row - s->height/2.0)*(4.0*s->zoom)/s->width;
			while (c->x * c->x + c->y * c->y < 4 && n++ < 1000)
			{
				x_new = c->x * c->x - c->y * c->y + c->c_re;
				c->y = 2 * c->x * c->y + c->c_im;
				c->x = x_new;
			}
			get_color(n, s, c);
			c->i++;
			c->col++;
			c->x = 0;
			c->y = 0;
			n = 0;
		}
		c->col = 0;
		c->row++;
	}
}

void	julia(t_coord *c, t_scene *s)
{
	int		n;	
	double	x_new;

	c->i = 0;
	x_new = 0;
	n = 0;
	c->x = (c->col - s->width/2.0)*(4.0*s->zoom)/s->width;
	c->y = (c->row - s->height/2.0)*(4.0*s->zoom)/s->width;
	while (c->row < s->height)
	{
		while (c->col < s->width)
		{
			while (c->x * c->x + c->y * c->y < 16 && n++ < 1000)
			{
				x_new = c->x * c->x - c->y * c->y;
				c->y = 2 * c->x * c->y + 0.156;
				c->x = x_new - 0.8;
			}
			c->x = (c->col - s->width/2.0)*(4.0*s->zoom)/s->width;
			c->y = (c->row - s->height/2.0)*(4.0*s->zoom)/s->width;
			get_color(n, s, c);
			c->i++;
			c->col++;
			n = 0;
		}
		c->col = 0;
		c->row++;
	}
}

void	tricorn(t_coord *c, t_scene *s)
{
	int		n;	
	double	x_new;

	x_new = 0;
	n = 0;
	c->i = 0;
	c->x = (c->col - s->width/2.0)*(4.0*s->zoom)/s->width;
	c->y = (c->row - s->height/2.0)*(4.0*s->zoom)/s->width;
	c->c_re = c->x;
	c->c_im = c->y;
	while (c->row < s->height)
	{
		while (c->col < s->width)
		{
			while (c->x * c->x + c->y * c->y < 4 && n++ < 1000)
			{
				x_new = c->x * c->x - c->y * c->y + c->c_re;
				c->y = -2 * c->x * c->y + c->c_im;
				c->x = x_new;
			}
			c->x = (c->col - s->width/2.0)*(4.0*s->zoom)/s->width;
			c->y = (c->row - s->height/2.0)*(4.0*s->zoom)/s->width;
			c->c_re = c->x;
			c->c_im = c->y;
			get_color(n, s, c);
			c->i++;
			c->col++;
			n = 0;
		}
		c->col = 0;
		c->row++;
	}
}

void	burningship(t_coord *c, t_scene *s)
{
	int		n;	
	double	x_new;

	x_new = 0;
	n = 0;
	c->i = 0;
	c->x = (c->col - s->width/2.0)*(4.0*s->zoom)/s->width;
	c->y = (c->row - s->height/2.0)*(4.0*s->zoom)/s->width;
	c->c_re = c->x;
	c->c_im = c->y;
	while (c->row < s->height)
	{
		while (c->col < s->width)
		{
			while (c->x * c->x + c->y * c->y < 4 && n++ < 1000)
			{
				x_new = c->x * c->x - c->y * c->y + c->c_re;
				c->y = ft_abs(2 * c->x * c->y + c->c_im);
				c->x = ft_abs(x_new);
			}
			c->x = (c->col - s->width/2.0)*(4.0*s->zoom)/s->width;
			c->y = (c->row - s->height/2.0)*(4.0*s->zoom)/s->width;
			c->c_re = c->x;
			c->c_im = c->y;
			get_color(n, s, c);
			c->i++;
			c->col++;
			n = 0;
		}
		c->col = 0;
		c->row++;
	}
}
