/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:48:55 by aszhilki          #+#    #+#             */
/*   Updated: 2020/01/31 21:05:02 by aszhilki         ###   ########.fr       */
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
	double		x;
	double		x_max;
	double		x_min;
	double		y;
	double		y_max;
	double		y_min;
	double		col;
	double		row;
	double		c_re;
	double		c_im;
	int			i;

}				t_coord;

typedef	struct	s_scene
{
	int			scheme;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*get_addr;
	double		height;
	double		width;
	int			*crd;
	double		zoom;
}				t_scene;

void			check_set(char **argv, t_coord *c, t_scene *s);
void			set_default(t_coord *c, t_scene *s);
void			create_scene(t_scene *s);
void			get_color(int n, t_scene *s, t_coord *c);
void			set_color(t_coord *c, t_scene *s, float ti);
int				key_press(int keycode, t_scene *s);
void			manage_keys(t_scene *s);
void			key_zoom(int keycode, t_scene *s);
void			mandelbrot(t_coord *c, t_scene *s);
void			julia(t_coord *c, t_scene *s);
void			tricorn(t_coord *c, t_scene *s);
void			burningship(t_coord *c, t_scene *s);
void			put_image(t_scene *s);
void			call(t_coord *c, t_scene *s);
int				set_fractal(char argv);

#endif
