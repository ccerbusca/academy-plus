/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 11:04:10 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/04 11:07:17 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void		ft_putnwstr(wchar_t *wstr, int n)
{
	unsigned int	i;

	i = 0;
	while (n > 0)
	{
		n -= sizeof_wchar(wstr[i]);
		ft_putwchar(wstr[i]);
		i++;
	}
}
