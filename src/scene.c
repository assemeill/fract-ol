/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:01:22 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/31 21:06:26 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_set(char **argv, t_coord *c, t_scene *s)
{
	create_scene(s);
	set_default(c, s);
	call(t_coord *c, t_scene *s);
	put_image(s);
	manage_keys(s);
//	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr, t->img, 0, 0);
	mlx_loop(s->mlx_ptr);
	n++;
	}
}

void	call(t_coord *c, t_scene *s)
{
	if (s->scheme == 1)
		julia(c, s);
	else if (s->scheme == 2)
		mandelbrot(c, s);
	else if (s->scheme == 3)
		tricorn(c, s);
	else if (s->scheme == 4)
		burningship(c, s);
}

int		set_fractal(char *argv)
{
	if (ft_strcheck(argv, "julia"))
		return(1);
	else if (ft_strcheck(argv, "mandelbrot"))
		return(2);
	else if (ft_strcheck(argv, "tricorn"))
		return(3);
	else if (ft_strcheck(argv, "burningship"))
		return(4);
}

void	put_image(t_scene *s)
{
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img, 0, 0);
}

void	set_default(t_coord *c, t_scene *s)
{
	c->y_min = -1;
	c->x_max = 1;
	c->i = 0;
	c->x = 0;
	c->y = 0;
	c->col = 0;
	c->row = 0;
	s->width = 800;
	s->height = 500;
	s->zoom = 1;
}

void	create_scene(t_scene *s)
{
	int		bpp;
	int		endian;
	int		sl;

	s->mlx_ptr = mlx_init();
	s->win_ptr = mlx_new_window(s->mlx_ptr, 800, 500, "fract'ol");
	s->img = mlx_new_image(s->mlx_ptr, 800, 500);
	s->get_addr = mlx_get_data_addr(s->img, &bpp, &sl, &endian);
}
