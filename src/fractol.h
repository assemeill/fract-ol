/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszhilki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:48:55 by aszhilki          #+#    #+#             */
/*   Updated: 2020/02/14 14:05:04 by aszhilki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>
# include <pthread.h>
# define HEIGHT 500
# define WIDTH 500
# define THREADS 20

typedef	struct	s_scene
{
	char		scheme;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*get_addr;
	int			*crd;
	float		zoom;
	float		x;
	float		x_max;
	float		x_min;
	float		y;
	float		y_max;
	float		max_y;
	float		y_min;
	int			col;
	int			row;
	float		c_re;
	float		c_im;
	int			i;
	float		x_c;
	float		y_c;
	int			move_x;
	int			move_y;
	float		intr;
	int			help;
	int			freeze;
	int			color;
}				t_scene;

void			check_set(t_scene *s);
void			set_default(t_scene *s);
void			create_scene(t_scene *s);
void			get_color(int n, t_scene *s);
void			set_color(t_scene *s, float ti);
float			scale(float start, float end);
void			mandelbrot(t_scene *s);
void			julia(t_scene *s);
void			tricorn(t_scene *s);
void			burningship(t_scene *s);
void			call(t_scene *s);
int				set_fractal(char *argv);
void			set_threads(t_scene *s);
void			set_help(t_scene *s);
void			set_text(t_scene *s);
void			manage_keys(t_scene *s);
int				key_press(int keycode, t_scene *s);
void			freeze_julia(t_scene *s);
void			help(t_scene *s);
void			change_color(t_scene *s);
void			key_move(int keycode, t_scene *s);
void			key_zoom(int keycode, t_scene *s);
int				mouse(int keycode, int x, int y, t_scene *s);
int				mouse_move(int x, int y, t_scene *s);
int				close_fr(t_scene *s);

#endif
