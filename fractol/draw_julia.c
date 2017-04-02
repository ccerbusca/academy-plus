/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:57:47 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/29 17:46:50 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_black	julia(t_black fr)
{
	t_deep	k;

	fr.juliax = -0.8 + fr.movex;
	fr.juliay = 0.156 + fr.movey;
	k.row = 0;
	while (k.row < HEIGHT)
	{
		k.col = 0;
		while (k.col < WIDTH)
		{
			k = init_var(fr, k);
			k.iteration = 0;
			while (k.x * k.x + k.y * k.y <= 4 && k.iteration < MAXITER)
			{
				k.xtemp = k.x;
				k.x = k.x * k.x - k.y * k.y + fr.juliax;
				k.y = 2 * k.xtemp * k.y + fr.juliay;
				k.iteration += SKIP;
			}
			fr = put_check(fr, k);
			k.col++;
		}
		k.row++;
	}
	return (fr);
}
