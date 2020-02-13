/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:31:42 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/11 21:08:12 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_scene *s[2];
	int		n;
	int		i;

	n = 1;
	i = 0;
	if (argc != 2 && argc != 3)
		ft_putstr("Invalid input\n");
//	while (argv[n])
//	{
		if (!(s[i] = (t_scene *)malloc(sizeof(t_scene))))
			return (0);
		s[i]->help = 1;
		s[i]->scheme = set_fractal(argv[n]);
		check_set(s[i]);
		n++;
		i++;
//	}
}
