/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:54:44 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/03/11 19:18:00 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		k_hook(int k_code, t_black *fr)
{
	if (k_code == 53)
		exit(0);
	if (k_code == 15)
	{
		fr = resetare(fr);
		expose_hook(fr);
	}
	if (k_code == 31)
		fr->sweetch++;
	return (0);
}

int		m_hook(int m_code, int x, int y, t_black *fr)
{
	if (m_code == 4)
	{
		fr->originx = x - (x - fr->originx) * 1.5;
		fr->originy = y - (y - fr->originy) * 1.5;
		fr->zoom *= 1.5;
		expose_hook(fr);
	}
	if (m_code == 5)
	{
		fr->originx = x - (x - fr->originx) / 1.5;
		fr->originy = y - (y - fr->originy) / 1.5;
		fr->zoom /= 1.5;
		expose_hook(fr);
	}
	return (0);
}

int		motion_hook(int x, int y, t_black *fr)
{
	if (fr->sweetch % 2 == 1)
	{
		fr->movex = (x - fr->originx) / fr->zoom;
		fr->movey = (y - fr->originy) / fr->zoom;
		expose_hook(fr);
	}
	return (0);
}

t_black	*resetare(t_black *fr)
{
	fr->originx = WIDTH / 2.0;
	fr->originy = HEIGHT / 2.0;
	fr->zoom = HEIGHT / 4;
	return (fr);
}
