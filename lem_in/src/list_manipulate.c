/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:26:34 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/23 15:27:37 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	save_line(t_read **save, char *str)
{
	t_read		*start;
	t_read		*aux;

	aux = (t_read*)malloc(sizeof(t_read));
	aux->line = str;
	aux->next = NULL;
	if (*save)
	{
		start = *save;
		while (start->next)
			start = start->next;
		start->next = aux;
	}
	else
		*save = aux;
}

t_node	*create_node(char *str)
{
	t_node		*aux;
	char		**tab;
	static int	indexer = -1;
	int			i;

	tab = ft_strsplit(str, ' ');
	if (!tab || count_char(str, ' ') != 2)
		err("ROOM IS INCORRECTLY SPECIFIED");
	aux = (t_node*)malloc(sizeof(t_node));
	aux->x = ft_atoi(tab[1]);
	aux->y = ft_atoi(tab[2]);
	aux->name = ft_strdup(tab[0]);
	aux->index = ++indexer;
	aux->next = NULL;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (aux);
}

void	push_back(t_node **lem, char *str)
{
	t_node		*start;

	if (*lem)
	{
		start = *lem;
		while (start->next)
			start = start->next;
		start->next = create_node(str);
	}
	else
		*lem = create_node(str);
}

int		list_size(t_node *node)
{
	if (node)
		return (1 + list_size(node->next));
	return (0);
}
