/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 11:10:13 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/12/27 15:11:26 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nbr_bits(unsigned int nbr)
{
	int i;

	i = 1;
	while ((nbr = nbr >> 1))
		i++;
	return (i);
}

void	ft_putwchar_fd(wchar_t wchar, int fd)
{
	unsigned int	ch;
	int				n;

	ch = (unsigned int)wchar;
	n = nbr_bits(ch);
	if (n > 7)
	{
		if (n > 11)
		{
			if (n > 16)
			{
				ft_putchar_fd(((ch >> 18) & 7) | 240, fd);
				ft_putchar_fd(((ch >> 12) & 63) | 128, fd);
			}
			else
				ft_putchar_fd(((ch >> 12) & 15) | 224, fd);
			ft_putchar_fd(((ch >> 6) & 63) | 128, fd);
		}
		else
			ft_putchar_fd(((ch >> 6) & 31) | 192, fd);
		ft_putchar_fd((ch & 63) | 128, fd);
	}
	else
		ft_putchar_fd(ch, fd);
}
