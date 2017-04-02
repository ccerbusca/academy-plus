/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xoxo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 11:15:26 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/20 17:02:59 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_o(t_printf *pr, unsigned long long nr)
{
	char	*str;
	int		len;

	pr->arg.semn = 0;
	pr->arg.blank = 0;
	if (pr->arg.prefix && nr == 0 && pr->arg.precision == 0)
		pr->arg.precision = -1;
	if (nr == 0)
		pr->arg.prefix = 0;
	str = ft_ulltoa_base(nr, 8, 0);
	print_string(pr, &str, 1);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		handle_x(t_printf *pr, unsigned long long nr)
{
	char	*str;
	int		len;

	pr->arg.semn = 0;
	pr->arg.blank = 0;
	str = ft_ulltoa_base(nr, 16, 0);
	if (nr == 0)
		pr->arg.prefix = 0;
	print_string(pr, &str, 2);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int		handle_xm(t_printf *pr, unsigned long long nr)
{
	char	*str;
	int		len;

	pr->arg.semn = 0;
	pr->arg.blank = 0;
	str = ft_ulltoa_base(nr, 16, 1);
	if (nr == 0)
		pr->arg.prefix = 0;
	print_string(pr, &str, 4);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
