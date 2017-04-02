/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:37:10 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/23 17:34:06 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countw(char *s, char c)
{
	int nr;

	nr = 0;
	while (*s)
	{
		if (*s != c)
		{
			nr++;
			while (*s && *s != c)
				s++;
			s--;
		}
		s++;
	}
	return (nr);
}

static int		ft_chr(char *s, char c)
{
	int nr;

	nr = 0;
	while (*s && *s != c)
	{
		nr++;
		s++;
	}
	return (nr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**aux;
	int		i;

	if (s == NULL)
		return (NULL);
	if (!(aux = (char**)malloc(sizeof(char*) * (ft_countw((char*)s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			aux[i] = ft_strsub(s, 0, ft_chr((char*)s, c));
			while (*s && *s != c)
				s++;
			i++;
		}
		else
			s++;
	}
	aux[i] = 0;
	return (aux);
}
