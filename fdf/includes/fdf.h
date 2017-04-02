/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 17:02:25 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/11/21 14:39:34 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1000
# define HEIGHT 1000

# define RED 0xFF0000
# define GREEN 0x00CC00
# define WHITE 0xFFFFFF
# define BLUE 0x0066FF
# define VIOLET 0xC200B2
# define AZURE 0x1DF2E4
# define ORANGE 0xF27D1D
# define YELLOW 0xF7EF07

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_matrix
{
	int			col;
	int			row;
	double		sp;
}				t_matrix;

typedef struct	s_scale
{
	int			x;
	int			y;
	int			z;
}				t_scale;

typedef struct	s_fdf
{
	void		*env;
	void		*win;
	int			colour;
	double		hophey;
	double		zoom;
	int			move_x;
	int			move_y;
	int			cos;
	int			sin;
	double		precision;
	t_scale		**tab;
	t_matrix	k;
}				t_fdf;

typedef struct	s_draw_line
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_draw_line;

typedef struct	s_coord
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_coord;

int				open_file(char *str);
int				get_col(char *s);
t_scale			*get_coord(char **aux, int col);
t_scale			**convert(char *s, t_matrix sizes);
t_matrix		get_sizes(char *s);
int				k_hook(int k_code, t_fdf *z);
void			draw_line(t_coord q, t_fdf fdf);
t_coord			init_coord(t_fdf z, int i, int j, int ok);
void			print_tab(t_fdf z);
void			in_it(t_fdf fdf);
t_fdf			*resetare(t_fdf *fdf);
t_fdf			isometric(t_fdf k);
int				compara(int a0, int a1);
int				compara2(int dx, int dy);
int				colour_change(void);
t_fdf			*movement(int k_code, t_fdf *z);
t_fdf			*movement_aux1(int k_code, t_fdf *z);
t_fdf			*movement_aux2(int k_code, t_fdf *z);
t_fdf			*height_control_and_zoom(int k_code, t_fdf *z);
t_fdf			*rotate(int k_code, t_fdf *z);
double			precision_switch(void);
t_fdf			fdf_init(char *argv);

#endif
