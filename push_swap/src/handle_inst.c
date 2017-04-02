/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:12:42 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/02/09 10:22:52 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_inst	get_instr(char *s)
{
	if (ft_strequ("sa", s))
		return (sa);
	else if (ft_strequ("sb", s))
		return (sb);
	else if (ft_strequ("ss", s))
		return (ss);
	else if (ft_strequ("pa", s))
		return (pa);
	else if (ft_strequ("pb", s))
		return (pb);
	else if (ft_strequ("ra", s))
		return (ra);
	else if (ft_strequ("rb", s))
		return (rb);
	else if (ft_strequ("rr", s))
		return (rr);
	else if (ft_strequ("rra", s))
		return (rra);
	else if (ft_strequ("rrb", s))
		return (rrb);
	else if (ft_strequ("rrr", s))
		return (rrr);
	else
		return (err());
}

void	in_push_back(t_in **inst, t_inst i)
{
	t_in		*ptr;
	t_in		*start;

	ptr = (t_in*)malloc(sizeof(t_in));
	ptr->i = i;
	ptr->next = NULL;
	start = *inst;
	if (start == NULL)
		*inst = ptr;
	else
	{
		while (start->next)
			start = start->next;
		start->next = ptr;
	}
}
