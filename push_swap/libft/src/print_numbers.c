/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:36:15 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/27 17:36:21 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		apply_precision(t_printf *pr, char **str, int type)
{
	int		len;
	char	*s;

	if (pr->arg.precision != -1 && pr->arg.precision > (int)ft_strlen(*str)
			- (*str[0] == '-'))
	{
		len = pr->arg.precision - ft_strlen(*str) + 1 + (*str[0] == '-');
		if (type == 1)
			len -= pr->arg.prefix;
		s = ft_strnew(len);
		ft_memset(s, '0', len - 1);
		if (*str[0] == '-')
			*str = ft_strjoin("-", ft_strjoin(s, (*str) + 1));
		else
			*str = ft_strjoin(s, *str);
		free(s);
	}
}

void		apply_sign(t_printf *pr, char **str)
{
	if (pr->arg.semn && *str[0] != '-')
		*str = ft_strjoin("+", *str);
	else if (pr->arg.blank && *str[0] != '-')
		*str = ft_strjoin(" ", *str);
}

void		apply_prefix(t_printf *pr, char **str, int type)
{
	if (pr->arg.prefix)
	{
		if (type == 1)
			*str = ft_strjoin("0", *str);
		else if (type == 2 || type == 3)
			*str = ft_strjoin("0x", *str);
		else if (type == 4)
			*str = ft_strjoin("0X", *str);
	}
}

void		apply_width(t_printf *pr, char **str, int type)
{
	char	*s;
	int		len;

	if ((int)ft_strlen(*str) < pr->arg.width && pr->arg.width != 0
		&& pr->arg.width > pr->arg.precision)
	{
		len = pr->arg.width - ft_strlen(*str) - ((pr->arg.semn || pr->arg.blank)
				&& *str[0] != '-') + 1;
		if (type == 1)
			len -= (pr->arg.prefix && pr->arg.zero);
		else if (type == 2 || type == 3 || type == 4)
			len -= 2 * (pr->arg.prefix && pr->arg.zero);
		s = ft_strnew(len);
		if (pr->arg.left || pr->arg.precision != -1)
			pr->arg.zero = 0;
		ft_memset(s, pr->arg.zero ? '0' : ' ', len - 1);
		if (pr->arg.left)
			*str = ft_strjoin(*str, s);
		else if ((*str[0] == '-' || *str[0] == '+') && pr->arg.zero)
			*str = ft_strjoin(*str[0] == '-' ? "-" : "+",
					ft_strjoin(s, (*str) + 1));
		else
			*str = ft_strjoin(s, *str);
		free(s);
	}
}

void		print_string(t_printf *pr, char **str, int type)
{
	if (pr->arg.precision == 0 && ft_atoi(*str) == 0)
		*str = "";
	apply_precision(pr, str, type);
	if (pr->arg.zero)
	{
		apply_width(pr, str, type);
		apply_prefix(pr, str, type);
		apply_sign(pr, str);
	}
	else
	{
		apply_prefix(pr, str, type);
		apply_sign(pr, str);
		pr->arg.blank = 0;
		pr->arg.semn = 0;
		pr->arg.prefix = 0;
		apply_width(pr, str, type);
	}
}
