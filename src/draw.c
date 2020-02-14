/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:31:33 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/13 17:38:32 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	call(t_scene *s)
{
	set_default(s);
	while (s->row < s->max_y)
	{
		while (s->col < WIDTH)
		{
			s->x = ((double)s->col - s->move_x) / s->intr + s->x_c;
			s->y = ((double)s->row - s->move_y) / s->intr + s->y_c;
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

void	set_default(t_scene *s)
{
	s->i = 0;
	s->x = 0;
	s->y = 0;
	s->col = 0;
	s->row = 0;
}

void	set_help(t_scene *s)
{
	int	max;
	int	i;
	int	red;

	i = 0;
	red = 0;
	max = HEIGHT * WIDTH * 4;
	while (i <= max)
	{
		if (i % 8772 == 0)
			red += 1;
		s->get_addr[i] = (char)150;
		s->get_addr[i + 1] = (char)red;
		s->get_addr[i + 2] = (char)44;
		s->get_addr[i + 3] = (char)60;
		i += 4;
	}
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img, 0, 0);
	set_text(s);
}

void	set_text(t_scene *s)
{
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 35), 140,
	0xFFFFFF, "FRACT'OL");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 35), 155,
	0xFFFFFF, "aszhilki");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 35), 180,
	0xFFFFFF, "controls");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 35), 220,
	0xFFFFFF, "+/- zoom");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 35), 240,
	0xFFFFFF, "ESC exit");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 45), 260,
	0xFFFFFF, "ARROWS move");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 110), 280,
	0xFFFFFF, "H open fractal/open help");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 73), 300,
	0xFFFFFF, "SPACE change color");
	mlx_string_put(s->mlx_ptr, s->win_ptr, (WIDTH / 2 - 73), 320,
	0xFFFFFF, "F freeze julia set");
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img, 0, 0);
}
