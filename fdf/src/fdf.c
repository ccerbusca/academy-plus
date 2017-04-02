/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 16:59:56 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/28 18:59:21 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		k_hook(int k_code, t_fdf *z)
{
	if (k_code == 53)
		exit(0);
	mlx_clear_window(z->env, z->win);
	if (k_code == 35)
		z = resetare(z);
	else if (k_code == 126 || k_code == 125 || k_code == 124 || k_code == 123)
		z = height_control_and_zoom(k_code, z);
	else if (k_code == 31 || k_code == 0 || k_code == 1 || k_code == 2
			|| k_code == 13)
		z = movement(k_code, z);
	else if (k_code == 37)
		z->precision = precision_switch();
	else if (k_code == 15)
		z->colour = colour_change();
	else if (k_code == 91 || k_code == 84 || k_code == 86 || k_code == 88)
		z = rotate(k_code, z);
	print_tab(*z);
	return (0);
}

t_fdf	fdf_init(char *argv)
{
	t_fdf fdf;

	fdf.k = get_sizes(argv);
	fdf.tab = convert(argv, fdf.k);
	fdf.colour = WHITE;
	fdf.hophey = 0.105;
	fdf.zoom = 1;
	fdf.move_x = 0;
	fdf.move_y = 0;
	fdf.cos = 30;
	fdf.sin = 40;
	fdf.precision = 1;
	return (fdf);
}

int		main(int argc, char **argv)
{
	t_fdf		fdf;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf <filename>");
		return (0);
	}
	fdf = fdf_init(argv[1]);
	in_it(fdf);
	return (0);
}
