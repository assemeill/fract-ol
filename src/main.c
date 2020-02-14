/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:31:42 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/13 17:13:41 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_scene *s;

	if (argc != 2 && argc != 3)
	{
		ft_putstr("Invalid input\n");
		exit(0);
	}
	if (!(s = (t_scene *)malloc(sizeof(t_scene))))
		return (0);
	s->help = 0;
	s->scheme = set_fractal(argv[1]);
	if (s->scheme == 0)
	{
		ft_putstr("Invalid input\n");
		free(s);
		exit(0);
	}
	check_set(s);
}
