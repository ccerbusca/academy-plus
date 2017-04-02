/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 14:53:09 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/12 16:12:13 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long nr;

	nr = n;
	if (nr < 0)
	{
		nr = -nr;
		ft_putchar('-');
	}
	if (nr > 9)
	{
		ft_putnbr(nr / 10);
		ft_putnbr(nr % 10);
	}
	else
		ft_putchar(nr + '0');
}
