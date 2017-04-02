/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xoxo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 11:15:26 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/12/27 12:33:03 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_o(t_printf *pr, unsigned long long nr)
{
	char *str;

	pr->arg.semn = 0;
	pr->arg.blank = 0;
	if (pr->arg.prefix && nr == 0 && pr->arg.precision == 0)
		pr->arg.precision = -1;
	if (nr == 0)
		pr->arg.prefix = 0;
	str = ft_ulltoa_base(nr, 8, 0);
	print_string(pr, &str, 1);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		handle_x(t_printf *pr, unsigned long long nr)
{
	char *str;

	pr->arg.semn = 0;
	pr->arg.blank = 0;
	str = ft_ulltoa_base(nr, 16, 0);
	if (nr == 0)
		pr->arg.prefix = 0;
	print_string(pr, &str, 2);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		handle_xm(t_printf *pr, unsigned long long nr)
{
	char *str;

	pr->arg.semn = 0;
	pr->arg.blank = 0;
	str = ft_ulltoa_base(nr, 16, 1);
	if (nr == 0)
		pr->arg.prefix = 0;
	print_string(pr, &str, 4);
	ft_putstr(str);
	return (ft_strlen(str));
}
