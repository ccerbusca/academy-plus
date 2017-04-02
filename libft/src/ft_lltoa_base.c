/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 15:54:40 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/12/24 15:54:42 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nrlen(unsigned long long i, int base)
{
	int nr;

	nr = 0;
	while (i != 0)
	{
		nr++;
		i /= base;
	}
	return (nr);
}

static char	calc(unsigned long long i)
{
	if (i > 9)
		return ('a' + i - 10);
	return (i + '0');
}

char		*ft_lltoa_base(long long nr, int base)
{
	char				*str;
	int					minus;
	int					len;
	unsigned long long	nb;

	minus = 0;
	if (nr < 0)
		minus = 1;
	nb = minus ? -nr : nr;
	len = nrlen(nb, base) + minus + 1;
	str = ft_strnew(len);
	str[--len] = 0;
	while (nb != 0)
	{
		str[--len] = calc(nb % base);
		nb /= base;
	}
	if (minus)
		str[len] = '-';
	return (str);
}
