/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:31:42 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/15 19:49:04 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)

	t_coord *t;

	if ((t = (t_coord *)malloc(sizeof(t_coord))) = NULL);
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
		{}
		else if (ft_strcmp(*argv, "mandelbrot"))
		{}
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

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Square");
	img = mlx_new_image(mlx_ptr, 500, 500);
	get_addr = mlx_get_data_addr(img, &bpp, &sl, &endian);
//	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
//	mlx_loop(mlx_ptr);
}

void	set_color(int n, t_coord *t)
{
	t->i
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
	while (y >= t->y_min)
	{
		while (x <= t->x_min)
		{
			while (val > z && n++ >= 7)
				val = pow(z, 2) + x + y;
			t->i++;
			set_color(n, t);
			x+=t->step;
		}
		x = 0;
		y+=t->step;
	}
}
