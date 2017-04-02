/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 15:54:40 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/29 23:56:27 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	calc(unsigned long long i, int capital)
{
	if (i > 9)
	{
		if (!capital)
			return ('a' + i - 10);
		else
			return ('A' + i - 10);
	}
	return (i + '0');
}

char		*ft_lltoa_base(long long nr, int base, int capital)
{
	char				*str;
	int					minus;
	int					len;
	unsigned long long	nb;

	minus = 0;
	if (nr < 0 && base == 10)
		minus = 1;
	nb = nr < 0 ? -nr : nr;
	len = ft_nrlen(nb, base) + minus + 1;
	str = ft_strnew(len);
	str[--len] = 0;
	while (len != 0 + minus)
	{
		str[--len] = calc(nb % base, capital);
		nb /= base;
	}
	if (minus)
		str[--len] = '-';
	return (str);
}
