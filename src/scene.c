/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:01:22 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/13 18:16:09 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	beg_values(t_scene *s)
{
	s->zoom = 1;
	s->y_min = 0;
	s->y_max = HEIGHT;
	s->x_min = 0;
	s->x_max = WIDTH;
	s->x_c = 0;
	s->y_c = 0;
	s->move_x = WIDTH / 2;
	s->move_y = HEIGHT / 2;
	s->intr = WIDTH / 4.0;
	s->freeze = 0;
	s->r = 0;
	s->g = 0;
	s->b = 0;
	s->color = 0;
}

void		check_set(t_scene *s)
{
	create_scene(s);
	set_default(s);
	beg_values(s);
	set_help(s);
	manage_keys(s);
	mlx_loop(s->mlx_ptr);
}

void		set_threads(t_scene *s)
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

int			set_fractal(char *argv)
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
}

void		create_scene(t_scene *s)
{
	int		bpp;
	int		endian;
	int		sl;

	s->mlx_ptr = mlx_init();
	s->win_ptr = mlx_new_window(s->mlx_ptr, WIDTH, HEIGHT, "fract'ol");
	s->img = mlx_new_image(s->mlx_ptr, WIDTH, HEIGHT);
	s->get_addr = mlx_get_data_addr(s->img, &bpp, &sl, &endian);
}
