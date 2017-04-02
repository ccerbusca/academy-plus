/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 16:31:17 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/10/24 16:40:05 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *d;

	d = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (d == NULL)
		return (NULL);
	ft_strcpy(d, s1);
	return (d);
}
