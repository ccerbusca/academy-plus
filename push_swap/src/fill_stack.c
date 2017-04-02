/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:34:43 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/02/15 17:34:33 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					count_numbers(char *str)
{
	int		nr;

	nr = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			nr++;
			while (ft_isdigit(*str))
				str++;
		}
		else
			str++;
	}
	return (nr);
}

t_stack			fill_stack(int ac, char **av, int debug)
{
	t_stack		stack;
	int			i;

	i = 1;
	i += debug;
	stack.stack = (int*)malloc(sizeof(int) * (ac - i));
	stack.nr = ac - i;
	while (i < ac)
	{
		check_digits(av[i]);
		check_overflow(av[i]);
		stack.stack[i - 1 - debug] = ft_atoi(av[i]);
		i++;
	}
	duplicate(stack.stack, ac - 1);
	return (stack);
}
