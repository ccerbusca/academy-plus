/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 18:41:37 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/03/23 17:00:54 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>
int		key_hook(int k_code, t_wolf *wolf)
{
	if (k_code == 53)
		exit(1);
	wolf->colour = wolf->colour;
	return (0);
}

int		key_loop(int k_code, t_wolf *wolf)
{
	if (k_code == 13)
	{
		if (!wolf->map[(int)(wolf->k.posx + wolf->k.dirx *
					wolf->k.ms)][(int)wolf->k.posy])
			wolf->k.posx += wolf->k.dirx * wolf->k.ms;
		if (!wolf->map[(int)wolf->k.posx][(int)(wolf->k.posy +
					wolf->k.diry * wolf->k.ms)])
			wolf->k.posy += wolf->k.diry * wolf->k.ms;
	}
	if (k_code == 1)
	{
		if (!wolf->map[(int)(wolf->k.posx - wolf->k.dirx
					* wolf->k.ms)][(int)wolf->k.posy])
			wolf->k.posx -= wolf->k.dirx * wolf->k.ms;
		if (!wolf->map[(int)wolf->k.posx][(int)(wolf->k.posy -
					wolf->k.diry * wolf->k.ms)])
			wolf->k.posy -= wolf->k.diry * wolf->k.ms;
	}
	if (k_code == 2)
	{
		wolf->k.old_dirx = wolf->k.dirx;
		wolf->k.dirx = wolf->k.dirx * cos(-wolf->k.rs) -
			wolf->k.diry * sin(-wolf->k.rs);
		wolf->k.diry = wolf->k.old_dirx * sin(-wolf->k.rs) +
			wolf->k.diry * cos(-wolf->k.rs);
		wolf->k.old_planex = wolf->k.planex;
		wolf->k.planex = wolf->k.planex * cos(-wolf->k.rs) -
			wolf->k.planey * sin(-wolf->k.rs);
		wolf->k.planey = wolf->k.old_planex * sin(-wolf->k.rs) +
			wolf->k.planey * cos(-wolf->k.rs);
	}
	if (k_code == 0)
	{
		wolf->k.old_dirx = wolf->k.dirx;
		wolf->k.dirx = wolf->k.dirx * cos(wolf->k.rs) -
			wolf->k.diry * sin(wolf->k.rs);
		wolf->k.diry = wolf->k.old_dirx * sin(wolf->k.rs) +
			wolf->k.diry * cos(wolf->k.rs);
		wolf->k.old_planex = wolf->k.planex;
		wolf->k.planex = wolf->k.planex * cos(wolf->k.rs) -
			wolf->k.planey * sin(wolf->k.rs);
		wolf->k.planey = wolf->k.old_planex * sin(wolf->k.rs) +
			wolf->k.planey * cos(wolf->k.rs);
	}
	new_img(*wolf);
	return (0);
}

int		ver_line(int x, int y1, int y2, t_wolf *wolf)
{
	int		y;
	int		offset;

	for(y = y2; y >= y1; y--)
	{
		offset = x * 4;
		offset += y * wolf->sline;
		*(int*)(wolf->str + offset) = wolf->colour;
	}
	return (1);
}

t_wolf	init_coordinates(t_wolf wolf)
{
	wolf.k.posx = 22;
	wolf.k.posy = 12;
	wolf.k.dirx = -1;
	wolf.k.diry = 0;
	wolf.k.planex = 0;
	wolf.k.planey = 0.66;
	wolf.k.ms = 0.3;
	wolf.k.rs = 0.08;
	return (wolf);
}

t_wolf	assign_color(t_wolf wolf)
{
	wolf.colour = YELLOW;
	if (wolf.map[wolf.k.mapx][wolf.k.mapy] == 1)
		wolf.colour = RED;
	if (wolf.map[wolf.k.mapx][wolf.k.mapy] == 2)
		wolf.colour = GREEN;
	if (wolf.map[wolf.k.mapx][wolf.k.mapy] == 3)
		wolf.colour = BLUE;
	if (wolf.map[wolf.k.mapx][wolf.k.mapy] == 4)
		wolf.colour = WHITE;
	if (wolf.k.side == 1)
		wolf.colour = ORANGE2;
	return (wolf);
}

t_wolf	wolfization(t_wolf wolf)
{
	for (wolf.k.x = 0; wolf.k.x < WIDTH; wolf.k.x++)
	{
		wolf.k.camerax = 2 * wolf.k.x / (double)wolf.w - 1;
		wolf.k.ray_posx = wolf.k.posx;
		wolf.k.ray_posy = wolf.k.posy;
		wolf.k.ray_dirx = wolf.k.dirx + wolf.k.planex * wolf.k.camerax;
		wolf.k.ray_diry = wolf.k.diry + wolf.k.planey * wolf.k.camerax;
		wolf.k.mapx = (int)wolf.k.ray_posx;
		wolf.k.mapy = (int)wolf.k.ray_posy;
		wolf.k.delta_distx = sqrt(1 + (wolf.k.ray_diry * wolf.k.ray_diry) /
				(wolf.k.ray_dirx * wolf.k.ray_dirx));
		wolf.k.delta_disty = sqrt(1 + (wolf.k.ray_dirx * wolf.k.ray_dirx) /
				(wolf.k.ray_diry * wolf.k.ray_diry));
		wolf.k.hit = 0;
		if (wolf.k.ray_dirx < 0)
		{
			wolf.k.stepx = -1;
			wolf.k.side_distx = (wolf.k.ray_posx - wolf.k.mapx) *
				wolf.k.delta_distx;
		}
		else
		{
			wolf.k.stepx = 1;
			wolf.k.side_distx = (wolf.k.mapx + 1.0 - wolf.k.ray_posx) *
				wolf.k.delta_distx;
		}
		if (wolf.k.ray_diry < 0)
		{
			wolf.k.stepy = -1;
			wolf.k.side_disty = (wolf.k.ray_posy - wolf.k.mapy) *
				wolf.k.delta_disty;
		}
		else
		{
			wolf.k.stepy = 1;
			wolf.k.side_disty = (wolf.k.mapy + 1.0 - wolf.k.ray_posy) *
				wolf.k.delta_disty;
		}
		while (wolf.k.hit == 0)
		{
			if (wolf.k.side_distx < wolf.k.side_disty)
			{
				wolf.k.side_distx += wolf.k.delta_distx;
				wolf.k.mapx += wolf.k.stepx;
				wolf.k.side = 0;
			}
			else
			{
				wolf.k.side_disty += wolf.k.delta_disty;
				wolf.k.mapy += wolf.k.stepy;
				wolf.k.side = 1;
			}
			if (wolf.map[wolf.k.mapx][wolf.k.mapy] > 0)
				wolf.k.hit = 1;
		}
		if (wolf.k.side == 0)
			wolf.k.perp_wall_dist = (wolf.k.mapx - wolf.k.ray_posx +
					(1 - wolf.k.stepx) / 2) / wolf.k.ray_dirx;
		else
			wolf.k.perp_wall_dist = (wolf.k.mapy - wolf.k.ray_posy +
					(1 - wolf.k.stepy) / 2) / wolf.k.ray_diry;
		wolf.k.line_height = (int)(wolf.h / wolf.k.perp_wall_dist);
		wolf.k.draw_start = -wolf.k.line_height / 2 + wolf.h / 2;
		if (wolf.k.draw_start < 0)
			wolf.k.draw_start = 0;
		wolf.k.draw_end = wolf.k.line_height / 2 + wolf.h / 2;
		if (wolf.k.draw_end >= wolf.h)
			wolf.k.draw_end = wolf.h - 1;
		wolf = assign_color(wolf);
		ver_line(wolf.k.x, wolf.k.draw_start, wolf.k.draw_end, &wolf);
	}
	return (wolf);
}

void	new_img(t_wolf wolf)
{
	wolf.h = HEIGHT;
	wolf.w = WIDTH;
	wolf.img_ptr = mlx_xpm_file_to_image(wolf.env, "moon.xpm", &wolf.h,
			&wolf.w);
	wolf.str = mlx_get_data_addr(wolf.img_ptr, &(wolf.bpp), &(wolf.sline),
			&(wolf.endian));
	wolf = wolfization(wolf);
	mlx_put_image_to_window(wolf.env, wolf.win, wolf.img_ptr, 0, 0);
}

void	in_it(t_wolf wolf)
{
	wolf.env = mlx_init();
	wolf.win = mlx_new_window(wolf.env, WIDTH, HEIGHT, "wolf3d");
	wolf = init_coordinates(wolf);
	new_img(wolf);
	mlx_key_hook(wolf.win, key_hook, &wolf);
	mlx_hook(wolf.win, KEYPRESSEVENT, KEYPRESSMASK, key_loop, &wolf);
	mlx_loop(wolf.env);
}

int		main(int argc, char **argv)
{
	t_wolf	wolf;

	if (argc != 2)
	{
		ft_putendl("Usage : ./wolf3d [map_name]");
		exit(1);
	}
	wolf.sizes = get_sizes(argv[1]);
	wolf.map = convert(argv[1], wolf.sizes);
	in_it(wolf);
	return (0);
}
