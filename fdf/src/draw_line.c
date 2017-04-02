/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 20:29:37 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/14 17:03:35 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(t_coord q, t_fdf fdf)
{
	t_draw_line r;

	r.dx = abs(q.x1 - q.x0);
	r.sx = compara(q.x0, q.x1);
	r.dy = abs(q.y1 - q.y0);
	r.sy = compara(q.y0, q.y1);
	r.err = compara2(r.dx, r.dy) / 2;
	while (1)
	{
		mlx_pixel_put(fdf.env, fdf.win, q.x0, q.y0, fdf.colour);
		if (q.x0 == q.x1 && q.y0 == q.y1)
			break ;
		r.e2 = r.err;
		if (r.e2 > -r.dx)
		{
			r.err -= r.dy;
			q.x0 += r.sx;
		}
		if (r.e2 < r.dy)
		{
			r.err += r.dx;
			q.y0 += r.sy;
		}
	}
}

int		compara2(int dx, int dy)
{
	if (dx > dy)
		return (dx);
	return (-dy);
}

int		compara(int a0, int a1)
{
	if (a0 < a1)
		return (1);
	return (-1);
}
