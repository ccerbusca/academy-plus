/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 09:04:39 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/02/09 10:00:28 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first2(t_stack *a)
{
	if (a->nr > 1)
	{
		a->stack[0] ^= a->stack[1];
		a->stack[1] ^= a->stack[0];
		a->stack[0] ^= a->stack[1];
	}
}

int		pop(t_stack **a)
{
	int		nr;
	int		i;

	if ((*a)->nr > 0)
	{
		nr = (*a)->stack[0];
		i = 0;
		(*a)->nr--;
		while (i < (*a)->nr)
		{
			(*a)->stack[i] = (*a)->stack[i + 1];
			i++;
		}
		return (nr);
	}
	return (0);
}

void	push_front(t_stack **a, int nr)
{
	int i;

	i = (*a)->nr;
	while (i > 0)
	{
		(*a)->stack[i] = (*a)->stack[i - 1];
		--i;
	}
	(*a)->stack[0] = nr;
	(*a)->nr++;
}

int		is_sorted(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	aff(t_stack a, t_stack b, t_inst inst)
{
	int					i;
	static const char	*in[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", \
								"rr", "rra", "rrb", "rrr"};

	i = 0;
	ft_printf("%s\na =====> ", in[inst]);
	while (i < a.nr)
	{
		ft_printf("%d ", a.stack[i]);
		i++;
	}
	ft_printf("\nb =====> ");
	i = 0;
	while (i < b.nr)
	{
		ft_printf("%d ", b.stack[i]);
		i++;
	}
	ft_printf("\n\n");
}
