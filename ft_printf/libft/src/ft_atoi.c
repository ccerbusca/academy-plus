/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 16:02:51 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/27 17:08:42 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		i;
	int		m;
	int		sign;

	i = 0;
	m = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (i > 0 && str[i - 1] == '-')
		sign = -1;
	while (str[i] && ft_isdigit(str[i]))
	{
		m = m * 10 + str[i] - '0';
		i++;
	}
	return (m * sign);
}
