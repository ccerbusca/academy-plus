/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:43:15 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/27 17:09:19 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*norminette_ftw(t_printf *pr, int length, int *len, char *c)
{
	*len = pr->arg.width - length;
	if (pr->arg.left)
		pr->arg.zero = 0;
	*c = pr->arg.zero ? '0' : ' ';
	return (pr);
}

void		init_flags(t_arg *ptr)
{
	ptr->left = 0;
	ptr->semn = 0;
	ptr->prefix = 0;
	ptr->zero = 0;
	ptr->blank = 0;
	ptr->width = 0;
	ptr->precision = -1;
	ptr->len = no;
}

int			check_if_sub_specifier(char c)
{
	if (!c)
		return (0);
	return (ft_strchr("+- #0123456789hljz.*", c) != NULL);
}

t_printf	*handle_wildcard(t_printf *pr)
{
	int nr;

	nr = va_arg(pr->ap, int);
	if (nr < 0)
	{
		pr->arg.left = 1;
		nr = -nr;
	}
	pr->arg.width = nr;
	return (pr);
}
