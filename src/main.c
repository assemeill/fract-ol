/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:31:42 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/31 20:59:25 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_coord *c;
	t_scene *s;
	int		n;

	n = 1;
	if (argc != 2 && argc != 3)
		ft_putstr("Invalid filename\n");
	if (!(s = (t_scene *)malloc(sizeof(t_scene))))
		return (0);
	if (!(c = (t_coord *)malloc(sizeof(t_coord))))
		return (0);
	while (argv[n])
	{
		set_fractal(argv[n]);	
		check_set(c, s);
		n++;
	}
}
