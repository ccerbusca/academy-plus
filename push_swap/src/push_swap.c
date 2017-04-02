/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 09:04:09 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/02/15 17:23:03 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec(t_stack *a, t_stack *b, t_inst i)
{
	if (i == pb)
	{
		push_front(&b, pop(&a));
		ft_putendl("pb");
	}
	else if (i == ra)
	{
		a->stack[a->nr++] = pop(&a);
		ft_putendl("ra");
	}
	else if (i == rra)
	{
		push_front(&a, a->stack[--a->nr]);
		ft_putendl("rra");
	}
}

void	divide(t_stack *a, t_stack *b, int m)
{
	int	min;

	min = get_min(a);
	if (is_sorted(a->stack, a->nr))
		return ;
	if (min <= m)
	{
		if (min == 0)
		{
			if (a->nr > 0)
				exec(a, b, pb);
			else
				return ;
		}
		else if (a->nr > 0)
			exec(a, b, ra);
		else
			return ;
	}
	else if (a->nr > 0)
		exec(a, b, rra);
	else
		return ;
	divide(a, b, a->nr / 2);
}

void	sort2(t_stack *a, t_stack *b)
{
	while (b->nr > 0)
	{
		push_front(&a, pop(&b));
		ft_putendl("pa");
	}
}

void	sort(t_stack a)
{
	t_stack b;

	b.stack = (int*)malloc(sizeof(int) * a.nr);
	b.nr = 0;
	divide(&a, &b, a.nr / 2);
	sort2(&a, &b);
	free(b.stack);
}

int		main(int argc, char **argv)
{
	t_stack		a;

	if (argc > 1)
	{
		if (argc == 2)
			a = fill_stack(count_numbers(argv[1]) + 1,
				ft_split(ft_strjoin("0 ", argv[1])), 0);
		else
			a = fill_stack(argc, argv, 0);
		sort(a);
		free(a.stack);
	}
	return (0);
}
