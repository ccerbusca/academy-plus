/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:00:23 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/23 17:38:26 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void	hex_simulator_init(t_lem *lem)
{
	lem->ants = (int*)malloc(sizeof(int) * lem->nr_ants);
	lem->v = (int*)malloc(sizeof(int) * lem->n);
	lem->parents = (int*)malloc(sizeof(int) * lem->n);
	fill(lem->ants, lem->ants + lem->nr_ants, lem->start->index);
	fill(lem->v, lem->v + lem->n, 0);
}

int		next_is_not_busy(int *ants, int nr_ants, int next)
{
	int i;

	i = 0;
	while (i < nr_ants)
	{
		if (ants[i] == next)
			return (0);
		i++;
	}
	return (1);
}

void	print_saved_lines(t_lem lem)
{
	t_read		*aux;

	while (lem.save)
	{
		ft_printf("%s\n", lem.save->line);
		aux = lem.save;
		lem.save = lem.save->next;
		free(aux->line);
		free(aux);
	}
	ft_printf("\n");
}

void	destroy(t_lem *lem)
{
	t_node	*aux;
	int		i;

	free(lem->ants);
	free(lem->parents);
	free(lem->v);
	free(lem->start->name);
	free(lem->end->name);
	free(lem->start);
	free(lem->end);
	free(lem->arr);
	while (lem->list)
	{
		aux = lem->list;
		lem->list = lem->list->next;
		free(aux->name);
		free(aux);
	}
	i = 0;
	while (i < lem->n)
	{
		free(lem->map[i]);
		i++;
	}
	free(lem->map);
}

int		main(void)
{
	t_lem		lem;

	lem.save = NULL;
	read_graph(&lem);
	print_saved_lines(lem);
	hex_simulator(&lem);
	destroy(&lem);
	return (0);
}
