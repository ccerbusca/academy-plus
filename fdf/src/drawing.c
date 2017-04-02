/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:36:58 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/29 20:14:40 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	init_coord(t_fdf z, int i, int j, int ok)
{
	t_coord	q;

	q.y0 = z.tab[i][j].y;
	q.x0 = z.tab[i][j].x;
	if (ok == 1)
	{
		q.x1 = z.tab[i + 1][j].x;
		q.y1 = z.tab[i + 1][j].y;
	}
	else
	{
		q.x1 = z.tab[i][j + 1].x;
		q.y1 = z.tab[i][j + 1].y;
	}
	return (q);
}

void	print_tab(t_fdf z)
{
	int		i;
	int		j;
	t_coord	q;

	i = 0;
	z = isometric(z);
	while (i < z.k.row)
	{
		j = 0;
		while (j < z.k.col)
		{
			if (i < z.k.row - 1)
			{
				q = init_coord(z, i, j, 1);
				draw_line(q, z);
			}
			if (j < z.k.col - 1)
			{
				q = init_coord(z, i, j, 2);
				draw_line(q, z);
			}
			j++;
		}
		i++;
	}
}

void	in_it(t_fdf fdf)
{
	fdf.env = mlx_init();
	fdf.win = mlx_new_window(fdf.env, HEIGHT, WIDTH, "fdf");
	print_tab(fdf);
	mlx_key_hook(fdf.win, k_hook, &fdf);
	mlx_loop(fdf.env);
}

t_fdf	isometric(t_fdf fdf)
{
	int		i;
	int		j;
	double	cos30;
	double	sin30;

	cos30 = cos(fdf.cos * M_PI / 180);
	sin30 = sin(fdf.sin * M_PI / 180);
	i = 0;
	fdf.k.sp *= fdf.zoom;
	while (i < fdf.k.row)
	{
		j = 0;
		while (j < fdf.k.col)
		{
			fdf.tab[i][j].x = (i - fdf.k.row / 2) * fdf.k.sp * -cos30
				+ (j - fdf.k.col / 2) * fdf.k.sp * cos30
				+ WIDTH / 2 + fdf.move_x;
			fdf.tab[i][j].y = (i - fdf.k.row / 2) * fdf.k.sp * sin30
				- (j - fdf.k.col / 2) * fdf.k.sp * -sin30 - fdf.tab[i][j].z
				* fdf.hophey * fdf.k.sp + HEIGHT / 2 + fdf.move_y;
			j++;
		}
		i++;
	}
	return (fdf);
}
