/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:55:17 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/03/15 18:50:24 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_black *fr)
{
	if (fr->type == 'M')
		*fr = mandelbrot(*fr);
	else if (fr->type == 'B')
		*fr = burning(*fr);
	else if (fr->type == 'J')
		*fr = julia(*fr);
	mlx_put_image_to_window(fr->env, fr->win, fr->img_ptr, 0, 0);
	return (0);
}

void	init_mlx(t_black *fr)
{
	fr->env = mlx_init();
	fr->win = mlx_new_window(fr->env, WIDTH, HEIGHT, "fract'ol");
	fr->originx = WIDTH / 2.0;
	fr->originy = HEIGHT / 2.0;
	fr->zoom = HEIGHT / 4;
	fr->sweetch = 0;
	fr->img_ptr = mlx_new_image(fr->env, WIDTH, HEIGHT);
	fr->str = mlx_get_data_addr(fr->img_ptr, &(fr->bps), &(fr->sline),
			&(fr->endian));
}

void	print_error(void)
{
	ft_putendl("Usage: ./fractol [mandelbrot/burningship/julia]");
	exit(1);
}

char	check_fractal(char *str)
{
	if (ft_strequ(str, "mandelbrot"))
		return ('M');
	else if (ft_strequ(str, "burningship"))
		return ('B');
	else if (ft_strequ(str, "julia"))
		return ('J');
	else
		print_error();
	return (0);
}

int		main(int argc, char **argv)
{
	t_black		fr;

	if (argc != 2)
		print_error();
	fr.type = check_fractal(argv[1]);
	init_mlx(&fr);
	mlx_key_hook(fr.win, k_hook, &fr);
	mlx_expose_hook(fr.win, expose_hook, &fr);
	mlx_hook(fr.win, MOTIONNOTIFY, MOTIONMASK, motion_hook, &fr);
	mlx_mouse_hook(fr.win, m_hook, &fr);
	mlx_loop(fr.env);
	return (0);
}
