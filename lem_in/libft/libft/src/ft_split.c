/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:33:39 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/03/05 17:51:10 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_ws(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\0')
		return (1);
	return (0);
}

int		countw(char *s)
{
	int nr;

	nr = 0;
	while (*s)
	{
		if (!ft_ws(*s))
		{
			nr++;
			while (!ft_ws(*s))
				s++;
			s--;
		}
		s++;
	}
	return (nr);
}

char	*ft_aux(char *str, char **aux1, int *z)
{
	char	*aux;
	int		i;

	i = 0;
	aux = (char*)malloc(sizeof(char) * 100);
	while (!ft_ws(*str))
	{
		aux[i] = *str;
		i++;
		str++;
	}
	str--;
	aux[i] = 0;
	*aux1 = aux;
	*z = *z + 1;
	return (str);
}

char	**ft_split(char *str)
{
	char	**aux;
	int		i;
	int		k;

	if (str == NULL)
		return (NULL);
	k = countw(str);
	aux = (char**)malloc(sizeof(char*) * (k + 1));
	i = 0;
	while (*str)
	{
		if (!ft_ws(*str))
			str = ft_aux(str, &aux[i], &i);
		str++;
	}
	if (k == 1)
	{
		aux[i] = 0;
		aux[i - 2] = 0;
	}
	else
		aux[i] = 0;
	return (aux);
}
