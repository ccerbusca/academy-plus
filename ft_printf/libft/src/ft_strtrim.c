/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 17:44:04 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/23 16:11:02 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkws(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*aux;
	int		i;

	if (s == NULL)
		return (0);
	aux = (char*)s;
	while (checkws(*aux))
		aux++;
	aux = ft_strdup(aux);
	if (aux == NULL)
		return (NULL);
	i = ft_strlen(aux) - 1;
	while (checkws(aux[i]) && i >= 0)
	{
		aux[i] = '\0';
		i--;
	}
	return (aux);
}
