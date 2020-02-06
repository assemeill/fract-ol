/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:00:02 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/05 17:23:21 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press(int keycode, t_scene *s)
{ 
	if (keycode == 69)// || keycode == 78 || keycode == 24 || keycode == 27)
		key_zoom(keycode, s);
	if (keycode == 53)
		exit(0);
//		ft_close(t->win_ptr, t);
//	if (keycode == 49 || keycode == 48)
//		change_pr(keycode, t);
//	if (keycode >= 123 && keycode <= 126)
//		key_move(keycode, t);
	return (0);
}

void	key_zoom(int keycode, t_scene *s)
{
	if (keycode == 69)
	{
		s->zoom *= 0.8;
		set_default(s);
		call(s);
		put_image(s);
	}
}

int		mouse(int keycode, int x, int y, t_scene *s)
{
//	float	re;
//	float	im;
	s->x_c = x;
	s->y_c = y;	
	if (keycode == 4 || keycode == 5)
	{
//		re = (float)x / (WIDTH / (s->x_max - s->x_min)) + s->x_min;
	//	im = (float)y / (HEIGHT / (s->y_max - s->y_min )) * -1 + s->y_max;
		if (keycode == 5)
			s->zoom *= 0.85;
		else if (keycode == 4)
			s->zoom /= 0.9;
	//	s->x_min = scale(re, s->x_min);
	//	s->y_min = scale(im, s->y_min);
	//	s->x_max = scale(re, s->x_max);
	//	s->y_max = scale(im, s->y_max);
	}
		set_default(s);
		call(s);
		put_image(s);
	return (0);
}

float	scale(float start, float end)
{
	return (start + ((end - start)));
}

void	manage_keys(t_scene *s)
{
	mlx_hook(s->win_ptr, 2, 0, key_press, s);
	mlx_hook(s->win_ptr, 4, 0, mouse, s);
}
