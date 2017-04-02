/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:54:25 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/19 19:56:20 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	calc(unsigned long long i, int capital)
{
	if (i > 9)
		if (!capital)
			return ('a' + i - 10);
		else
			return ('A' + i - 10);
	else
		;
	return (i + '0');
}

char		*ft_ulltoa_base(unsigned long long nb, int base, int capital)
{
	char				*str;
	int					len;

	len = ft_nrlen(nb, base) + 1;
	str = ft_strnew(len);
	str[--len] = 0;
	while (len != 0)
	{
		str[--len] = calc(nb % base, capital);
		nb /= base;
	}
	return (str);
}
