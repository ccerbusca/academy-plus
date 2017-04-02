/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:52:57 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/12/28 13:53:57 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(wchar_t *wstr)
{
	size_t len;

	len = 0;
	while (*wstr)
		len += sizeof_wchar(*wstr++);
	return (len);
}
