/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sub_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:42:40 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/27 17:32:48 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*check_precision(t_printf *pr, char **str)
{
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			pr->arg.precision = va_arg(pr->ap, int);
			if (pr->arg.precision < 0)
				pr->arg.precision = -1;
			(*str)++;
		}
		else
		{
			pr->arg.precision = ft_atoi(*str);
			while (**str && ft_isdigit(**str))
				(*str)++;
		}
		if (**str == '.')
			pr = check_precision(pr, str);
	}
	return (pr);
}

int			is_length_modifier(t_printf **pr, char **str)
{
	if (**str == 'h')
		if (*((*str) + 1) == 'h' && *((*str) + 1) != 0)
		{
			(*str)++;
			(*pr)->arg.len = (*pr)->arg.len > hh ? (*pr)->arg.len : hh;
		}
		else
			(*pr)->arg.len = (*pr)->arg.len > h ? (*pr)->arg.len : h;
	else if (**str == 'l')
		if (*((*str) + 1) == 'l' && *((*str) + 1) != 0)
		{
			(*str)++;
			(*pr)->arg.len = (*pr)->arg.len > ll ? (*pr)->arg.len : ll;
		}
		else
			(*pr)->arg.len = (*pr)->arg.len > l ? (*pr)->arg.len : l;
	else if (**str == 'j')
		(*pr)->arg.len = (*pr)->arg.len > j ? (*pr)->arg.len : j;
	else if (**str == 'z')
		(*pr)->arg.len = (*pr)->arg.len > z ? (*pr)->arg.len : z;
	else
		return (0);
	return (1);
}

t_printf	*check_length_modifiers(t_printf *pr, char **str)
{
	while (**str)
	{
		if (!is_length_modifier(&pr, str))
			break ;
		(*str)++;
	}
	return (pr);
}

t_printf	*check_flags(t_printf *pr, char **str)
{
	while (**str)
	{
		if (**str == '+')
			pr->arg.semn = 1;
		else if (**str == '-')
			pr->arg.left = 1;
		else if (**str == ' ')
			pr->arg.blank = 1;
		else if (**str == '#')
			pr->arg.prefix = 1;
		else if (**str == '0')
			pr->arg.zero = 1;
		else
			break ;
		(*str)++;
	}
	return (pr);
}

t_printf	*check_sub_specifiers(t_printf *pr, char **str)
{
	int width;

	pr->arg.nothing = 0;
	pr = check_flags(pr, str);
	if (**str == '*')
	{
		pr = handle_wildcard(pr);
		(*str)++;
	}
	width = ft_atoi(*str);
	if (pr->arg.width != 0)
	{
		if (width != 0)
			pr->arg.width = width;
	}
	else
		pr->arg.width = width;
	while (ft_isdigit(**str))
		(*str)++;
	pr = check_precision(pr, str);
	pr = check_length_modifiers(pr, str);
	if (check_if_sub_specifier(**str))
		pr = check_sub_specifiers(pr, str);
	return (pr);
}
