/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:51:43 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/29 17:47:12 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH 600
# define HEIGHT 600
# define MAXITER 752
# define SKIP 1
# define MOTIONMASK (1L<<6)
# define MOTIONNOTIFY 6

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct	s_black
{
	void		*env;
	void		*win;
	void		*img_ptr;
	int			bps;
	int			sline;
	int			endian;
	void		*str;
	double		originx;
	double		originy;
	double		zoom;
	char		type;
	double		juliax;
	double		juliay;
	double		movex;
	double		movey;
	int			sweetch;
}				t_black;

typedef struct	s_deep
{
	int			row;
	int			col;
	double		x0;
	double		y0;
	double		x;
	double		y;
	int			iteration;
	double		xtemp;
}				t_deep;

int				k_hook(int k_code, t_black *fr);
int				m_hook(int m_code, int x, int y, t_black *fr);
t_black			put_less(t_black fr, int iter, t_deep k);
t_black			put_equal(t_black fr, t_deep k);
t_black			put_check(t_black fr, t_deep k);
t_black			mandelbrot(t_black fr);
t_black			burning(t_black fr);
void			init_mlx(t_black *fr);
t_black			*resetare(t_black *fr);
int 			expose_hook(t_black *fr);
void			print_error(void);
char			check_fractal(char *str);
int				motion_hook(int x, int y, t_black *fr);
t_black			julia(t_black fr);
t_deep			init_var(t_black fr, t_deep k);

#endif
