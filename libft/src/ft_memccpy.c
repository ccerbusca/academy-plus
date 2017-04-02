/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 16:45:43 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/10/24 16:51:32 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	k;
	unsigned char	*ptr;

	k = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		if (((char*)src)[i] == c)
		{
			ptr = &((unsigned char*)dst)[i + 1];
			return (ptr);
		}
		i++;
	}
	return (NULL);
}
