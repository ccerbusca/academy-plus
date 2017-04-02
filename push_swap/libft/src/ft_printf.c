/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 09:13:51 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/27 17:09:08 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_arguments(t_printf *pr, char **str)
{
	int ret;

	init_flags(&pr->arg);
	(*str)++;
	pr->arg.nothing = 1;
	if (check_if_sub_specifier(**str))
		pr = check_sub_specifiers(pr, str);
	ret = check_specifier(pr, **str);
	return (ret);
}

int			go(t_printf *pr, char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		if (*str == '%')
			len += check_arguments(pr, &str);
		else
		{
			ft_putchar(*str);
			len++;
		}
		if (*str)
			str++;
	}
	return (len);
}

int			ft_printf(const char *restrict str, ...)
{
	t_printf	*pr;
	int			len;

	pr = (t_printf*)malloc(sizeof(t_printf));
	va_start(pr->ap, str);
	len = go(pr, (char*)str);
	va_end(pr->ap);
	return (len);
}
