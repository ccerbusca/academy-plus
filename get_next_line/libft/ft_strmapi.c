/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 16:14:48 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/23 15:26:51 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*aux;
	unsigned int		i;

	if (s == NULL || f == NULL)
		return (0);
	aux = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		aux[i] = f(i, s[i]);
		i++;
	}
	return (aux);
}
