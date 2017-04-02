/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 16:02:51 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/10/27 16:57:14 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_ok(int ok, int m)
{
	if (ok == 0)
		return (m);
	else
		return (m * (-1));
}

int			ft_atoi(const char *str)
{
	int		i;
	int		m;
	int		ok;

	i = 0;
	m = 0;
	ok = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i - 1] == '-')
		ok = 1;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			m = m * 10 + str[i] - '0';
		else
			return (check_ok(ok, m));
		i++;
	}
	return (check_ok(ok, m));
}
