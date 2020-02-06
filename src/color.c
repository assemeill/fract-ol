/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:01:57 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/04 13:55:02 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void	set_color(int n, t_coord *t)
//{
//	char	c[3];

//	c[0] = (sin(0.16 * n + 1) * 256 + 25);
//	if (n > 200)
//	{
//		t->get_addr[t->i * 4] = (char)255;
//		t->get_addr[t->i * 4 + 1] = (char)255;
//		t->get_addr[t->i * 4 + 2] = (char)255;
//	}
//	else
//	{
//		t->get_addr[t->i * 4] = (char)0;
//		t->get_addr[t->i * 4 + 1] = (char)255;
//		t->get_addr[t->i * 4 + 2] = (char)0;
//	}
//}
//

void	get_color(int n, t_scene *s)
{
	float	ti;	
	ti = n / (float)1000;
//	if (ti == 1)
//	{
//		t->get_addr[t->i * 4] = (char)0;
//		t->get_addr[t->i * 4 + 1] = (char)0;
//		t->get_addr[t->i * 4 + 2] = (char)0;
//	}
//	else
	set_color(s, ti);
}

void	set_color(t_scene *s, float ti)
{
	s->get_addr[s->i * 4] = (char)(6 * pow((1 - ti), 3) * ti * 255);
	s->get_addr[s->i * 4 + 1] = (char)(8.5 * (1 - ti) * pow(ti, 3) * 255);
	s->get_addr[s->i * 4 + 2] = (char)(14.5 * pow((1 - ti), 2) * pow(ti, 2) * 255);;
}
