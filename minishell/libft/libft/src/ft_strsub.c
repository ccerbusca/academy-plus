/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 17:16:22 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/07 19:55:26 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*aux;
	unsigned int	i;

	if (s == NULL)
		return (0);
	aux = (char*)malloc(sizeof(char) * (len + 1));
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		aux[i] = s[start];
		i++;
		start++;
	}
	aux[i] = 0;
	return (aux);
}
