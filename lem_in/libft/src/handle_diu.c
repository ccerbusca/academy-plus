/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:32:05 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/20 17:01:49 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_decimal(t_printf *pr, long long nr)
{
	char	*str;
	int		len;

	str = ft_lltoa_base(nr, 10, 0);
	print_string(pr, &str, 0);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		handle_u(t_printf *pr, unsigned long long nr)
{
	char	*str;
	int		len;

	pr->arg.blank = 0;
	pr->arg.semn = 0;
	str = ft_ulltoa_base(nr, 10, 0);
	print_string(pr, &str, 0);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
