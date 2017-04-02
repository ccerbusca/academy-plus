/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:57:47 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/29 17:47:00 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_black	burning(t_black fr)
{
	t_deep	k;

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
				k.x = k.x * k.x - k.y * k.y - k.x0;
				k.y = fabs(2 * k.xtemp * k.y) + k.y0;
				k.iteration += SKIP;
			}
			fr = put_check(fr, k);
			k.col++;
		}
		k.row++;
	}
	return (fr);
}
