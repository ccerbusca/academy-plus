/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 17:30:10 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/23 15:30:51 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	aux = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		aux[i] = (char)s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		aux[i] = (char)s2[j];
		i++;
		j++;
	}
	aux[i] = '\0';
	return (aux);
}
