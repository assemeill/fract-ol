/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:01:22 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/30 16:02:31 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_set(char **argv, t_coord *t)
{
// Add to work with two windows at a time.
//	while (*argv)	
//	{
		create_scene(t);
		set_default(t);
		if (ft_strcheck(argv[1], "julia"))
			julia(t);
		else if (ft_strcheck(argv[1], "mandelbrot"))
			mandelbrot(t);
		else if (ft_strcheck(argv[1], "tricorn"))
			tricorn(t);
		else if (ft_strcheck(argv[1], "burningship"))
			burningship(t);
	put_image(t);
	manage_keys(t);
//	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr, t->img, 0, 0);
	mlx_loop(t->mlx_ptr);
//	}
}

void	put_image(t_coord *t)
{
	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr, t->img, 0, 0);
}

void	set_default(t_coord *t)
{
	t->y_min = -1;
	t->x_max = 1;
	t->width = 800;
	t->height = 500;
	t->i = 0;
	t->zoom = 1;
}

void	create_scene(t_coord *t)
{
	int		bpp;
	int		endian;
	int		sl;

	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, 800, 500, "fract'ol");
	t->img = mlx_new_image(t->mlx_ptr, 800, 500);
	t->get_addr = mlx_get_data_addr(t->img, &bpp, &sl, &endian);
}
