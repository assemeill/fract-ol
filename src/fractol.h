/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:48:55 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/25 20:18:52 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>

typedef	struct	s_coord
{
	int			scheme;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*get_addr;
	double		x_max;
	double		y_min;
	int			height;
	int			width;
	int			i;
	int			*crd;
}				t_coord;

void			check_set(char **argv, t_coord *t);
void			set_default(t_coord *t);
void			create_scene(t_coord *t);
void			set_color(int n, t_coord *t);
void			mandelbrot(t_coord *t);
void			julia(t_coord *t);

#endif
