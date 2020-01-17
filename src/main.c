/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:31:42 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/16 19:14:03 by aszhilki         ###   ########.fr       */
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
	t->step = 0.01;
	t->y_min = -2.5;
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
	if (n == 7)	
	{
		t->get_addr[t->i * 4] = (char)255;
		t->get_addr[t->i * 4 + 1] = (char)255;
		t->get_addr[t->i * 4 + 2] = (char)255;
	}
	else
	{
		t->get_addr[t->i * 4] = (char)0;
		t->get_addr[t->i * 4 + 1] = (char)0;
		t->get_addr[t->i * 4 + 2] = (char)0;
	}
}

void	calculate(t_coord *t)
{
	int		n;	
	float	x;
	float	y;
	float	z;
	float	val;
	
	x = 0;
	y = 0;
	z = 0;
	n = 0;
	t->i = 0;
	val = 1;
	while (y >= t->y_min)
	{
		while (x <= t->x_max)
		{
			while (val > z && n++ <= 7)
			{
				val = pow(z, 2) + x + y;
				z = val;
			}
			t->i++;
			set_color(n, t);
			x = x + t->step;
			val = 1;
			n = 0;
		}
		x = 0;
		y = y + t->step;
	}
}
