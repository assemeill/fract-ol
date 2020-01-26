/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:31:42 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/25 20:25:26 by aszhilki         ###   ########.fr       */
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
			julia(t);
		else if (ft_strcmp(*argv, "mandelbrot"))
			mandelbrot(t);
	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr, t->img, 0, 0);
	mlx_loop(t->mlx_ptr);
//	}
}

void	set_default(t_coord *t)
{
	t->y_min = -1;
	t->x_max = 1;
	t->width = 800;
	t->height = 500;
	t->i = 0;
}

void	create_scene(t_coord *t)
{
	int		bpp;
	int		endian;
	int		sl;
//	int		i = 300601;

	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, 800, 500, "fract'ol");
	t->img = mlx_new_image(t->mlx_ptr, 800, 500);
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
		while (x*x + y*y < 16 && n++ <= 200)
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
	int		width;
	int		height;	
	int		n;	
	double	col;
	double	row;
	double	c_re;
	double	c_im;
	double	x;
	double	x_new;
	double	y;

	width = 800;
	height = 500;
	row = 0;
	col = 0;
	t->i = 0;
	x = 0;
	x_new = 0;
	y = 0;
	n = 0;
	while (row < height)
	{
		while (col < width)
		{
		c_re = (col - width/2.0)*4.0/width;
		c_im = (row - height/2.0)*4.0/width;
		while (x*x+y*y <= 4 && n++ <= 200)
			{
				x_new = x*x - y*y - 0.8;
				y = 2*x*y + 0.156;
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
