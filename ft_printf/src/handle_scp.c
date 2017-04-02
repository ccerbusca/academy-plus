/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_scp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:28:50 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/20 17:30:50 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_strings_chars(t_printf *pr, char *str, int length)
{
	int		len;
	int		i;
	char	c;

	len = 0;
	if (pr->arg.width != 0 && pr->arg.width - length > 0)
	{
		pr = norminette_ftw(pr, length, &len, &c);
		i = -1;
		if (pr->arg.left)
		{
			ft_putnstr(str, length);
			while (++i < len)
				ft_putchar(c);
		}
		else
		{
			while (++i < len)
				ft_putchar(c);
			ft_putnstr(str, length);
		}
	}
	else
		ft_putnstr(str, length);
	return (length + len);
}

int		handle_s(t_printf *pr, char *str)
{
	int aff;
	int len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (pr->arg.precision > -1)
		aff = pr->arg.precision < len ? pr->arg.precision : len;
	else
		aff = len;
	return (print_strings_chars(pr, str, aff));
}

int		handle_c(t_printf *pr, char c)
{
	if (pr->arg.nothing)
	{
		ft_putchar(c);
		return (1);
	}
	return (print_strings_chars(pr, &c, 1));
}

int		handle_nothing(t_printf *pr, char c)
{
	if (c)
		return (handle_c(pr, c));
	return (0);
}

int		handle_p(t_printf *pr, long long ad)
{
	char	*str;
	int		len;

	pr->arg.prefix = 1;
	pr->arg.semn = 0;
	pr->arg.blank = 0;
	str = ft_lltoa_base(ad, 16, 0);
	print_string(pr, &str, 3);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
