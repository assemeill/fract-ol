/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:47:40 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/14 11:59:54 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_move(int x, int y, t_scene *s)
{
	if (s->help == 0 || s->freeze == 1)
		return (0);
	s->c_re = (((float)x - WIDTH) / (WIDTH / 2)) + 1;
	s->c_im = (((float)y - WIDTH) / (WIDTH / 2)) + 1;
	set_threads(s);
	return (0);
}
