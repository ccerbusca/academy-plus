/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:32:52 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/23 17:00:28 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_graph(t_lem *lem)
{
	lem->line = return_line();
	if (!lem->line)
		err("EMPTY FILE");
	get_nr_ants(lem);
	save_line(&lem->save, lem->line);
	read_nodes(lem);
	if (!lem->start || !lem->end)
		err("START NODE OR END NODE NOT SPECIFIED");
	create_map(lem);
	check_duplicates(lem);
	get_links(lem);
}

void	get_nr_ants(t_lem *lem)
{
	int		i;

	lem->nr_ants = ft_atoi(lem->line);
	i = 0;
	while (lem->line[i])
	{
		if (!ft_isdigit(lem->line[i]))
			err("NUMBER OF ANTS IS INCORRECTLY SPECIFIED");
		i++;
	}
}

void	get_links(t_lem *lem)
{
	while (lem->line)
	{
		if (lem->line[0] == '#')
		{
			if (lem->line[1] == '#')
				err("INCORRECT OBLIGATORY COMMENT");
		}
		else
			fill_tab(lem);
		save_line(&lem->save, lem->line);
		lem->line = return_line();
	}
}

void	check_comments(t_lem *lem)
{
	if (lem->line[1] != '#')
		return ;
	if (ft_strequ(lem->line, "##start"))
	{
		if (lem->start)
			err("YOU HAVE TO SPECIFY ONLY 1 START NODE");
		save_line(&lem->save, lem->line);
		push_back(&lem->start, (lem->line = return_line()));
	}
	else if (ft_strequ(lem->line, "##end"))
	{
		if (lem->end)
			err("YOU HAVE TO SPECIFY ONLY 1 END NODE");
		save_line(&lem->save, lem->line);
		push_back(&lem->end, (lem->line = return_line()));
	}
	else
		err("INVALID COMMENT");
}

void	read_nodes(t_lem *lem)
{
	while ((lem->line = return_line()))
	{
		if (lem->line[0] == '#')
			check_comments(lem);
		else if (!ft_strchr(lem->line, ' '))
			return ;
		else
			push_back(&lem->list, lem->line);
		save_line(&lem->save, lem->line);
	}
}
