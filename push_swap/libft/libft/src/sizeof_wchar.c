/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizeof_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:40:47 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/12/28 13:50:19 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sizeof_wchar(wchar_t c)
{
	if (c < 0x7F)
		return (1);
	else if (c < 0x7FF)
		return (2);
	else if (c < 0xFFFF)
		return (3);
	return (4);
}
