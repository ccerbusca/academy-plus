/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 16:58:14 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/02/15 17:32:54 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	execute3(t_stack *a, t_stack *b, t_inst i)
{
	if (i == rrb)
	{
		if (b->nr > 0)
			push_front(&b, b->stack[--b->nr]);
	}
	else if (i == rrr)
	{
		if (a->nr > 0)
			push_front(&a, a->stack[--a->nr]);
		if (b->nr > 0)
			push_front(&b, b->stack[--b->nr]);
	}
}

void	execute2(t_stack *a, t_stack *b, t_inst i)
{
	if (i == ra)
	{
		if (a->nr > 0)
			a->stack[a->nr++] = pop(&a);
	}
	else if (i == rb)
	{
		if (b->nr > 0)
			b->stack[b->nr++] = pop(&b);
	}
	else if (i == rr)
	{
		if (a->nr > 0)
			a->stack[a->nr++] = pop(&a);
		if (b->nr > 0)
			b->stack[b->nr++] = pop(&b);
	}
	else if (i == rra)
	{
		if (a->nr > 0)
			push_front(&a, a->stack[--a->nr]);
	}
	else
		execute3(a, b, i);
}

void	execute(t_stack *a, t_stack *b, t_inst i)
{
	if (i == sa)
		swap_first2(a);
	else if (i == sb)
		swap_first2(b);
	else if (i == ss)
	{
		swap_first2(a);
		swap_first2(b);
	}
	else if (i == pa)
	{
		if (b->nr > 0)
			push_front(&a, pop(&b));
	}
	else if (i == pb)
	{
		if (a->nr > 0)
			push_front(&b, pop(&a));
	}
	else
		execute2(a, b, i);
}

t_stack	execute_order66(t_stack a, int debug)
{
	t_stack	b;
	char	*line;
	t_in	*inst;
	t_in	*leak;

	inst = NULL;
	b.stack = (int*)malloc(sizeof(int) * a.nr);
	b.nr = 0;
	while (get_next_line(0, &line) > 0)
		in_push_back(&inst, get_instr(line));
	while (inst)
	{
		execute(&a, &b, inst->i);
		if (debug)
			aff(a, b, inst->i);
		leak = inst;
		inst = inst->next;
		free(leak);
	}
	if (b.nr > 0)
		ft_printf("KO\n");
	if (b.nr > 0)
		exit(-42);
	free(b.stack);
	return (a);
}

int		main(int argc, char **argv)
{
	t_stack		a;
	int			debug;

	debug = 0;
	if (argc > 1)
	{
		if (ft_strequ("-v", argv[1]))
			debug = 1;
		if (argc - debug == 2)
			a = fill_stack(count_numbers(argv[1 + debug]) + 1,
				ft_split(ft_strjoin("0 ", argv[1 + debug])), 0);
		else
			a = fill_stack(argc, argv, debug);
		a = execute_order66(a, debug);
		if (is_sorted(a.stack, a.nr))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		ft_printf("\n");
	free(a.stack);
	return (0);
}
