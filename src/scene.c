/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:01:22 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/12 17:41:25 by aszhilki         ###   ########.fr       */
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
	s->x_c = 0;
	s->y_c = 0;
	s->move_x = WIDTH / 2;
	s->move_y = HEIGHT / 2;
	s->intr =WIDTH / 4.0;
	set_help(s);
//	s->max_iter = 100;
//	set_threads(s);
	manage_keys(s);
	mlx_loop(s->mlx_ptr);
}

void	set_help(t_scene *s)
{
	int	max;
	int	i;
	int	color;

	i = -1;
	color = 0;	
	max = HEIGHT * WIDTH * 4;	
	while (++i <= max)
	{
		s->get_addr[i] = (char)color;
		if (i == max && color != 160)
		{
			mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img, 0, 0);
			color += 1;
			i = -1;
		}
	}
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 35), 140, 0xFFFFFF, "FRACT'OL");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 35), 155, 0xFFFFFF, "aszhilki");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 35), 180, 0xFFFFFF, "controls");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 35), 220, 0xFFFFFF, "+/- zoom");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 35), 240, 0xFFFFFF, "ESC exit");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 45), 260, 0xFFFFFF, "ARROWS move");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 110), 280,
	0xFFFFFF, "H open fractal/open help");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 73), 300,
	0xFFFFFF, "SPACE change color");
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img, 0, 0);

}

void	call(t_scene *s)
{
	set_default(s);
	while (s->row < s->max_y)
	{
		while (s->col < WIDTH)
		{
			s->x = (s->col - s->move_x) / s->intr + s->x_c;
			s->y = (s->row - s->move_y) / s->intr + s->y_c;
			if (s->scheme == 1)
				julia(s);
			else if (s->scheme == 2)
				mandelbrot(s);
			else if (s->scheme == 3)
				tricorn(s);
			else if (s->scheme == 4)
				burningship(s);
			s->i++;
			s->col++;
		}
		s->col = 0;
		s->row++;
	}
}

void	set_threads(t_scene *s)
{
	t_scene			new_s[THREADS];
	pthread_t		threads[THREADS];
	int				i;

	i = 0;
	while (i < THREADS)
	{
		new_s[i] = *s;
		new_s[i].row = i * (HEIGHT / THREADS);
		new_s[i].max_y = (i + 1) * (HEIGHT / THREADS);
		pthread_create(&threads[i], NULL, (void *)call, (void *)&new_s[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img, 0, 0);
}

int		set_fractal(char *argv)
{
	if (ft_strcheck(argv, "julia"))
		return (1);
	else if (ft_strcheck(argv, "mandelbrot"))
		return (2);
	else if (ft_strcheck(argv, "tricorn"))
		return (3);
	else if (ft_strcheck(argv, "burningship"))
		return (4);
	return (0);
// Add smth what if 0?
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
	s->win_ptr = mlx_new_window(s->mlx_ptr, WIDTH, HEIGHT, "fract'ol");
	s->img = mlx_new_image(s->mlx_ptr, WIDTH, HEIGHT);
	s->get_addr = mlx_get_data_addr(s->img, &bpp, &sl, &endian);
}
