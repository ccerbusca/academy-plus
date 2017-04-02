/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wsc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:31:58 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/20 17:02:55 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_wstrings_wchars(t_printf *pr, wchar_t *str, int length)
{
	int		len;
	char	c;
	int		i;

	len = 0;
	if (pr->arg.width != 0 && pr->arg.width - length > 0)
	{
		pr = norminette_ftw(pr, length, &len, &c);
		i = -1;
		if (pr->arg.left)
		{
			ft_putnwstr(str, length);
			while (++i < len)
				ft_putchar(c);
		}
		else
		{
			while (++i < len)
				ft_putchar(c);
			ft_putnwstr(str, length);
		}
	}
	else
		ft_putnwstr(str, length);
	return (length + len);
}

int			wchar_calc_precision(wchar_t *wstr, int n)
{
	int count;

	count = 0;
	while (*wstr && n > 0)
	{
		if ((n -= sizeof_wchar(*wstr)) < 0)
			break ;
		count += sizeof_wchar(*wstr);
		wstr++;
	}
	return (count);
}

int			handle_sm(t_printf *pr, wchar_t *str)
{
	int		aff;
	int		len;

	if (str == NULL)
		str = L"(null)";
	if (pr->arg.nothing)
	{
		ft_putwstr(str);
		return (ft_wstrlen(str));
	}
	len = ft_wstrlen(str);
	if (pr->arg.precision > -1)
		aff = pr->arg.precision < len ? pr->arg.precision : len;
	else
		aff = len;
	return (print_wstrings_wchars(pr, str, wchar_calc_precision(str, aff)));
}

int			handle_cm(t_printf *pr, wchar_t c)
{
	if (pr->arg.nothing)
	{
		ft_putwchar(c);
		return (sizeof_wchar(c));
	}
	return (print_wstrings_wchars(pr, &c, sizeof_wchar(c)));
}
