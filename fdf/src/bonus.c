/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 19:50:35 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/03/12 20:00:31 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*rotate(int k_code, t_fdf *z)
{
	if (k_code == 91)
		z->sin += 10;
	else if (k_code == 84)
		z->sin -= 10 * z->precision;
	else if (k_code == 86)
		z->cos -= 10 * z->precision;
	else if (k_code == 88)
		z->cos += 10 * z->precision;
	return (z);
}

t_fdf	*height_control_and_zoom(int k_code, t_fdf *z)
{
	if (k_code == 126)
		z->hophey += 0.105 * z->precision;
	if (k_code == 125)
		z->hophey -= 0.105 * z->precision;
	if (k_code == 124)
		z->zoom *= 1.2 * z->precision;
	if (k_code == 123)
		z->zoom /= 1.2 * z->precision;
	return (z);
}

t_fdf	*resetare(t_fdf *z)
{
	z->colour = WHITE;
	z->hophey = 0.105;
	z->zoom = 1;
	z->move_x = 0;
	z->move_y = 0;
	z->cos = 30;
	z->sin = 40;
	z->precision = 1;
	return (z);
}

int		colour_change(void)
{
	static int	index = 1;
	int			colour;

	colour = WHITE;
	if (index % 8 == 1)
		colour = RED;
	if (index % 8 == 2)
		colour = GREEN;
	if (index % 8 == 3)
		colour = BLUE;
	if (index % 8 == 4)
		colour = VIOLET;
	if (index % 8 == 5)
		colour = AZURE;
	if (index % 8 == 6)
		colour = ORANGE;
	if (index % 8 == 7)
		colour = YELLOW;
	index++;
	return (colour);
}

double	precision_switch(void)
{
	static int	k = 1;
	double		i;

	i = 1;
	if (k % 2 == 1)
		i = 1.5;
	k++;
	return (i);
}
