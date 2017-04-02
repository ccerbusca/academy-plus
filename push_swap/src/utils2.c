/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 09:04:47 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/02/15 17:30:13 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		err(void)
{
	ft_putendl_fd("Error", 1);
	exit(-42);
	return (1);
}

void	check_digits(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			err();
		str++;
	}
}

void	check_overflow(char *str)
{
	long long	nr;
	int			minus;

	nr = 0;
	minus = 0;
	if (*str == '-')
		minus = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		nr = nr * 10 + *str - '0';
		if (minus)
		{
			if ((double)nr / (1 << 31) < -1.0)
				err();
		}
		else if ((double)nr / (~(1 << 31)) > 1.0)
			err();
		str++;
	}
}

void	duplicate(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack[i] == stack[j])
				err();
			j++;
		}
		i++;
	}
}

int		get_min(t_stack *a)
{
	int	i;
	int	min;

	i = 1;
	min = 0;
	while (i < a->nr)
	{
		if (a->stack[i] < a->stack[min])
			min = i;
		i++;
	}
	return (min);
}
