/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 15:59:28 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/12/24 15:05:20 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*aux;
	int		i;

	if (s == NULL || f == NULL)
		return (0);
	aux = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		aux[i] = f(s[i]);
		i++;
	}
	aux[i] = 0;
	return (aux);
}
