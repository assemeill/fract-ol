/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:31:42 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/14 13:42:55 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_scene *s;

	if (argc != 2 && argc != 3)
	{
		ft_putstr("Invalid input: choose julia, mandelbrot, ");
		ft_putstr("tricorn or burningship\n");
		exit(0);
	}
	if (!(s = (t_scene *)malloc(sizeof(t_scene))))
		return (0);
	s->help = 0;
	s->scheme = set_fractal(argv[1]);
	if (s->scheme == 0)
	{
		ft_putstr("Invalid input: choose julia, mandelbrot, ");
		ft_putstr("tricorn or burningship\n");
		free(s);
		exit(0);
	}
	check_set(s);
}
