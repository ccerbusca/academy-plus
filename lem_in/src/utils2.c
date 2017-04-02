/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:36:02 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/23 14:59:36 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_arr(t_lem *lem)
{
	t_node		*aux;
	t_node		*list;

	lem->arr = (t_node*)malloc(sizeof(t_node) * lem->n);
	list = lem->list;
	while (list)
	{
		aux = list->next;
		lem->arr[list->index] = *list;
		list = aux;
	}
	lem->arr[lem->start->index] = *lem->start;
	lem->arr[lem->end->index] = *lem->end;
}

void	create_map(t_lem *lem)
{
	int i;
	int j;

	lem->n = list_size(lem->list) + 2;
	lem->map = (int**)malloc(sizeof(int*) * lem->n);
	i = 0;
	while (i < lem->n)
	{
		lem->map[i] = (int*)malloc(sizeof(int) * lem->n);
		j = 0;
		while (j < lem->n)
		{
			lem->map[i][j] = 0;
			j++;
		}
		i++;
	}
	create_arr(lem);
}

int		get_index(t_lem *lem, char *name)
{
	int i;

	i = 0;
	while (i < lem->n)
	{
		if (ft_strequ(lem->arr[i].name, name))
			return (i);
		i++;
	}
	return (-1);
}

void	check_duplicates(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	while (i < lem->n - 1)
	{
		j = i + 1;
		while (j < lem->n)
		{
			if ((lem->arr[i].x == lem->arr[j].x
					&& lem->arr[i].y == lem->arr[j].y)
					|| ft_strequ(lem->arr[i].name, lem->arr[j].name))
				err("DUPLICATE NODES WERE FOUND");
			j++;
		}
		i++;
	}
}

int		check_ants(int *ants, int nr_ants, int end)
{
	int i;

	i = 0;
	while (i < nr_ants)
	{
		if (ants[i] != end)
			return (1);
		i++;
	}
	return (0);
}
