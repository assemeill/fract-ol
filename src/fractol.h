/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:48:55 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/05 16:53:47 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>
# define HEIGHT 500
# define WIDTH 800
typedef	struct	s_scene
{
	int			scheme;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*get_addr;
	int			*crd;
	double		zoom;
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
	int			x_c;
	int			y_c;
}				t_scene;

void			check_set(t_scene *s);
void			set_default(t_scene *s);
void			create_scene(t_scene *s);
void			get_color(int n, t_scene *s);
void			set_color(t_scene *s, float ti);
int				key_press(int keycode, t_scene *s);
int				mouse(int keycode, int x, int y, t_scene *s);
float			scale(float start, float end);
void			manage_keys(t_scene *s);
void			key_zoom(int keycode, t_scene *s);
void			mandelbrot(t_scene *s);
void			julia(t_scene *s);
void			tricorn(t_scene *s);
void			burningship(t_scene *s);
void			put_image(t_scene *s);
void			call(t_scene *s);
int				set_fractal(char *argv);

#endif
