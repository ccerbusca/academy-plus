/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:42:12 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/03/23 14:43:30 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H

# define WOLF3D_H

# define WIDTH 600
# define HEIGHT 600

# define RED 0xFF0000
# define GREEN 0x00CC00
# define WHITE 0xFFFFFF
# define BLUE 0x0066FF
# define YELLOW 0xF7EF07
# define ORANGE 0xED7905
# define ORANGE2 0xED841A

# define KEYPRESSEVENT 2
# define KEYPRESSMASK (1L<<0)

# include "libft/libft.h"
# include "fcntl.h"
# include <mlx.h>
# include <math.h>

typedef struct	s_matrix
{
	int			col;
	int			row;
}				t_matrix;

typedef struct	s_deep
{
	int			x;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		ray_posx;
	double		ray_posy;
	double		ray_dirx;
	double		ray_diry;
	int			mapx;
	int			mapy;
	double		side_distx;
	double		side_disty;
	double		delta_distx;
	double		delta_disty;
	double		perp_wall_dist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		move_speed;
	double		rot_speed;
	double		old_dirx;
	double		old_planex;
	double		ms;
	double		rs;
}				t_deep;

typedef struct	s_wolf
{
	void		*env;
	void		*win;
	void		*img_ptr;
	int			bpp;
	int			sline;
	int			endian;
	int			**map;
	void		*str;
	int			w;
	int			h;
	int			colour;
	t_matrix	sizes;
	t_deep		k;
}				t_wolf;

typedef struct	s_draw_line
{
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			e2;
}				t_draw_line;

void			in_it(t_wolf wolf);
int				key_hook(int k_code, t_wolf *wolf);
int				open_file(char *str);
int				get_col(char *s);
int				*get_coord(char **aux, int col);
int				**convert(char *s, t_matrix sizes);
t_matrix		get_sizes(char *s);
t_wolf			wolfization(t_wolf wolf);
void			new_img(t_wolf wolf);

#endif
