/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:43:15 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/20 18:24:28 by ccerbusc         ###   ########.fr       */
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

char		*no_leak_strjoin(char *s1, char *s2, int f1, int f2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (f1 == 1)
		free(s1);
	if (f2 == 1)
		free(s2);
	if (f2 == 2)
		free(s2 - 1);
	if (f1 == 2)
		free(s1 - 1);
	return (str);
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
