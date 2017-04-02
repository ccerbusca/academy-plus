/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 15:11:40 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/12 16:16:40 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long k;

	k = n;
	if (k < 0)
	{
		k = -k;
		ft_putchar_fd('-', fd);
	}
	if (k > 9)
	{
		ft_putnbr_fd(k / 10, fd);
		ft_putnbr_fd(k % 10, fd);
	}
	else
		ft_putchar_fd(k + '0', fd);
}
