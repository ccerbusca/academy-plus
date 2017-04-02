/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 14:13:01 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/11 17:03:00 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = ft_strlen(s);
	if (c == 0)
	{
		ptr = (char*)&s[i];
		return (ptr);
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			ptr = (char*)&s[i];
			return (ptr);
		}
		i--;
	}
	return (NULL);
}
