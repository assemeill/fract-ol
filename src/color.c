/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:01:57 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/13 18:36:45 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_color(int n, t_scene *s)
{
	float	ti;

	ti = n / (float)200;
	if (ti == 1)
	{
		s->get_addr[s->i * 4] = (char)0;
		s->get_addr[s->i * 4 + 1] = (char)0;
		s->get_addr[s->i * 4 + 2] = (char)0;
	}
	else
		set_color(s, ti);
}

void	set_color(t_scene *s, float ti)
{
	if (s->color == 0)
	{
	s->get_addr[s->i * 4] = (char)((6 + s->b) * pow((1 - ti), 3) * ti * 255);
	s->get_addr[s->i * 4 + 1] = (char)((8.5 + s->g) * (1 - ti) * pow(ti, 3) * 230);
	s->get_addr[s->i * 4 + 2] = (char)((14.5 + s->r) * pow((1 - ti), 2)
	* pow(ti, 2) * 255);
	s->get_addr[s->i * 4 + 3] = (char)0;
	}
	else if (s->color == 1)
	{
	s->get_addr[s->i * 4] = (char)((1 + s->g) * (1 - ti) * pow(ti, 3) * 230);
	s->get_addr[s->i * 4 + 1] = (char)((14.5 + s->r) * pow((1 - ti), 2)
	* pow(ti, 2) * 255);
	s->get_addr[s->i * 4 + 2] = (char)((6 + s->b) * pow((1 - ti), 3) * ti * 255);
	s->get_addr[s->i * 4 + 3] = (char)0;
	}
	else if (s->color == 2)
	{
	s->get_addr[s->i * 4] = (char)((14.5 + s->r) * pow((1 - ti), 2)
	* pow(ti, 2) * 255);
	s->get_addr[s->i * 4 + 1] = (char)((6 + s->b) * pow((1 - ti), 3) * ti * 255);
	s->get_addr[s->i * 4 + 2] = (char)((8.5 + s->g) * (1 - ti) * pow(ti, 3) * 230);
	s->get_addr[s->i * 4 + 3] = (char)0;
	}
}
