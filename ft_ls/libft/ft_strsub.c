/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 17:16:22 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/04/03 18:50:05 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*aux;
	unsigned int	i;

	if (s == NULL)
		return (0);
	aux = (char*)malloc(sizeof(*s) * len);
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		aux[i] = s[start];
		i++;
		start++;
	}
	return (aux);
}
