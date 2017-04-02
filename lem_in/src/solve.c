/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:03:18 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/23 15:04:29 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		bfs_aux(t_lem *lem, int c[], int bottom, int *top)
{
	int i;

	i = 0;
	while (i < lem->n)
	{
		if (lem->map[c[bottom]][i] && !lem->v[i])
		{
			c[++(*top)] = i;
			lem->v[i] = 1;
			lem->parents[i] = c[bottom];
			if (i == lem->end->index)
			{
				free(c);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int		bfs(t_lem *lem, int start)
{
	int *c;
	int top;
	int bottom;

	c = (int*)malloc(sizeof(int) * lem->n);
	top = 0;
	bottom = 0;
	lem->v[start] = 1;
	c[bottom] = start;
	lem->parents[start] = -1;
	while (bottom <= top)
	{
		if (bfs_aux(lem, c, bottom, &top))
			return (1);
		bottom++;
	}
	free(c);
	return (0);
}

int		next_step(int parents[], int st, int sf)
{
	if (parents[sf] != st)
		return (next_step(parents, st, parents[sf]));
	return (sf);
}

void	print_path(t_lem *lem, int ant)
{
	int next;

	if (bfs(lem, lem->ants[ant]))
	{
		next = next_step(lem->parents, lem->ants[ant], lem->end->index);
		lem->ants[ant] = next;
		ft_printf("L%d-%s ", ant + 1, lem->arr[next].name);
	}
	else
	{
		next = next_step(lem->parents, lem->ants[ant], lem->end->index);
		if (next != lem->end->index
			&& next_is_not_busy(lem->ants, lem->nr_ants, next))
		{
			lem->ants[ant] = next;
			ft_printf("L%d-%s ", ant + 1, lem->arr[next].name);
		}
	}
}

void	hex_simulator(t_lem *lem)
{
	int i;
	int kk;

	hex_simulator_init(lem);
	while (check_ants(lem->ants, lem->nr_ants, lem->end->index))
	{
		i = 0;
		while (i < lem->nr_ants)
		{
			if (lem->ants[i] != lem->end->index)
			{
				fill(lem->v, lem->v + lem->n, 0);
				kk = 0;
				while (kk < i)
				{
					if (lem->ants[kk] != lem->end->index)
						lem->v[lem->ants[kk]] = 1;
					kk++;
				}
				print_path(lem, i);
			}
			i++;
		}
		ft_putendl("");
	}
}
