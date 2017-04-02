/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 20:25:44 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/03/06 20:39:44 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*movement(int k_code, t_fdf *z)
{
	static int	k = 1;

	if (k % 2 == 1)
		z = movement_aux1(k_code, z);
	else
		z = movement_aux2(k_code, z);
	if (k_code == 31)
		k++;
	return (z);
}

t_fdf	*movement_aux1(int k_code, t_fdf *z)
{
	if (k_code == 0)
		z->move_x -= 30 * z->precision;
	if (k_code == 1)
		z->move_y += 30 * z->precision;
	if (k_code == 2)
		z->move_x += 30 * z->precision;
	if (k_code == 13)
		z->move_y -= 30 * z->precision;
	return (z);
}

t_fdf	*movement_aux2(int k_code, t_fdf *z)
{
	if (k_code == 0)
		z->move_x += 30 * z->precision;
	if (k_code == 1)
		z->move_y -= 30 * z->precision;
	if (k_code == 2)
		z->move_x -= 30 * z->precision;
	if (k_code == 13)
		z->move_y += 30 * z->precision;
	return (z);
}
