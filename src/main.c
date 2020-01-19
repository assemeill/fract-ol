/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:31:42 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/18 19:52:24 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_coord *t;

	if (!(t = (t_coord *)malloc(sizeof(t_coord))))
		return (0);
	if (argc != 2 && argc != 3)
		ft_putstr("Invalid filename\n");
	else
		check_set(argv, t);
}

void	check_set(char **argv, t_coord *t)
{
// Add to work with two windows at a time.
//	while (*argv)	
//	{
		create_scene(t);
		set_default(t);
		if (ft_strcmp(*argv, "julia"))
			calculate(t);
		else if (ft_strcmp(*argv, "mandelbrot"))
			calculate(t);
	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr, t->img, 0, 0);
	mlx_loop(t->mlx_ptr);
//	}
}

void	set_default(t_coord *t)
{
	t->step = 0.011;
	t->y_min = -1;
	t->x_max = 1;
}

void	create_scene(t_coord *t)
{
	int		bpp;
	int		endian;
	int		sl;
//	int		i = 300601;

	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, 500, 500, "fract'ol");
	t->img = mlx_new_image(t->mlx_ptr, 500, 500);
	t->get_addr = mlx_get_data_addr(t->img, &bpp, &sl, &endian);
//	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
//	mlx_loop(mlx_ptr);
}

void	set_color(int n, t_coord *t)
{
	if (n > 200)	
	{
		t->get_addr[t->i * 4] = (char)255;
		t->get_addr[t->i * 4 + 1] = (char)255;
		t->get_addr[t->i * 4 + 2] = (char)255;
	}
	else
	{
		t->get_addr[t->i * 4] = (char)0;
		t->get_addr[t->i * 4 + 1] = (char)255;
		t->get_addr[t->i * 4 + 2] = (char)0;
	}
}

void	calculate(t_coord *t)
{
	int		n;	
	double	x;
	double	y;
	double	z;
	double	val;
	
	x = -2;
	y = 1;
	z = 0;
	n = 0;
	t->i = 0;
	val = 0;
	while (y >= t->y_min)
	{
		while (x <= t->x_max)
		{
			while (ft_abs(z) < 2 && n++ <= 200)
			{
				z = val;
				val = pow(z, 2) + x + y;
			}
			z = 0;
			set_color(n, t);
			t->i++;
			x = x + t->step;
			val = 0;
			n = 0;
		}
		x = -2;
		y = y - t->step;
	}
}
