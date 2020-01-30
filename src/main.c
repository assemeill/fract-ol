/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:31:42 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/29 20:38:20 by aszhilki         ###   ########.fr       */
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
		if (ft_strcheck(argv[1], "julia"))
			julia(t);
		else if (ft_strcheck(argv[1], "mandelbrot"))
			mandelbrot(t);
		else if (ft_strcheck(argv[1], "tricorn"))
			tricorn(t);
		else if (ft_strcheck(argv[1], "burningship"))
			burningship(t);
	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr, t->img, 0, 0);
	manage_keys(t);
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
	t->zoom = 1;
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

int		key_press(int keycode, t_coord *t)
{
	if (keycode == 69)// || keycode == 78 || keycode == 24 || keycode == 27)
		key_zoom(keycode, t);
	if (keycode == 53)
		exit(0);
//		ft_close(t->win_ptr, t);
//	if (keycode == 49 || keycode == 48)
//		change_pr(keycode, t);
//	if (keycode >= 123 && keycode <= 126)
//		key_move(keycode, t);
	return (0);
}

void	key_zoom(int keycode, t_coord *t)
{
	keycode = 0;
	t->zoom *= 0.9;
	julia(t);
	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr, t->img, 0, 0);
}

void	manage_keys(t_coord *t)
{
	mlx_hook(t->win_ptr, 2, 0, key_press, t);
//	mlx_hook(t->win_ptr, 17, 0, ft_close, t);
}
