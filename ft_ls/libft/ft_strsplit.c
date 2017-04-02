/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 14:56:44 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/02/21 14:28:52 by ccerbusc         ###   ########.fr       */
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
			while (*s != c)
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
	while (*s != c)
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
		if (*s != c)
		{
			aux[i] = (char*)malloc(sizeof(char) * (ft_chr((char*)s, c) + 1));
			if (aux[i] == NULL)
				return (NULL);
			ft_strncpy(aux[i], s, ft_chr((char*)s, c));
			while (*s != c && *s)
				s++;
			i++;
		}
		else
			s++;
	}
	aux[i] = 0;
	return (aux);
}
