/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:32:05 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/27 16:32:07 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_decimal(t_printf *pr, long long nr)
{
	char *str;

	str = ft_lltoa_base(nr, 10, 0);
	print_string(pr, &str, 0);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		handle_u(t_printf *pr, unsigned long long nr)
{
	char	*str;

	pr->arg.blank = 0;
	pr->arg.semn = 0;
	str = ft_ulltoa_base(nr, 10, 0);
	print_string(pr, &str, 0);
	ft_putstr(str);
	return (ft_strlen(str));
}
