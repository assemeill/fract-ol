/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:01:22 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/05 16:56:19 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_set(t_scene *s)
{
	create_scene(s);
	set_default(s);
	s->zoom = 1;
	s->y_min = 0;
	s->y_max = HEIGHT;
	s->x_min = 0;
	s->x_max = WIDTH;
	s->x_c = 2.0;
	s->y_c = 4.0;
	call(s);
	put_image(s);
	manage_keys(s);
//	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr, t->img, 0, 0);
	mlx_loop(s->mlx_ptr);
}

void	call(t_scene *s)
{
	if (s->scheme == 1)
		julia(s);
	else if (s->scheme == 2)
		mandelbrot(s);
	else if (s->scheme == 3)
		tricorn(s);
	else if (s->scheme == 4)
		burningship(s);
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
	return(0);
// Add smth what if 0?
}

void	put_image(t_scene *s)
{
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img, 0, 0);
}

void	set_default(t_scene *s)
{
	s->i = 0;
	s->x = 0;
	s->y = 0;
	s->col = 0;
	s->row = 0;
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
