/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 16:02:14 by ccerbusc          #+#    #+#             */
/*   Updated: 2015/11/11 16:29:18 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*start;
	char	*ptr;
	char	*ptr2;

	start = (char*)s1;
	if (*s2 == 0)
		return ((char*)s1);
	if (*s1 == 0)
		return (NULL);
	while (*start != '\0')
	{
		ptr = start;
		ptr2 = (char*)s2;
		while (*ptr != '\0' && *ptr2 != '\0' && *ptr == *ptr2)
		{
			ptr++;
			ptr2++;
		}
		if (*ptr2 == '\0')
			return (start);
		start++;
	}
	return (NULL);
}
