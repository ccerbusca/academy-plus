/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:37:03 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/27 17:32:57 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_unsigned_integers2(t_printf *pr,
		int handle(t_printf *pr, unsigned long long))
{
	if (pr->arg.len == hh)
		return (handle(pr, (unsigned char)va_arg(pr->ap, int)));
	if (pr->arg.len == h)
		return (handle(pr, (unsigned short)va_arg(pr->ap, int)));
	if (pr->arg.len == l)
		return (handle(pr, va_arg(pr->ap, unsigned long)));
	if (pr->arg.len == ll)
		return (handle(pr, va_arg(pr->ap, unsigned long long)));
	if (pr->arg.len == j)
		return (handle(pr, va_arg(pr->ap, uintmax_t)));
	if (pr->arg.len == z)
		return (handle(pr, va_arg(pr->ap, size_t)));
	return (handle(pr, va_arg(pr->ap, unsigned int)));
}

int			check_unsigned_integers(t_printf *pr, char c)
{
	if (c == 'o')
		return (check_unsigned_integers2(pr, handle_o));
	if (c == 'O')
		return (handle_o(pr, va_arg(pr->ap, unsigned long)));
	if (c == 'u')
		return (check_unsigned_integers2(pr, handle_u));
	if (c == 'U')
		return (handle_u(pr, va_arg(pr->ap, unsigned long)));
	if (c == 'x')
		return (check_unsigned_integers2(pr, handle_x));
	if (c == 'X')
		return (check_unsigned_integers2(pr, handle_xm));
	return (handle_nothing(pr, c));
}

int			check_chars_strings(t_printf *pr, char c)
{
	if (c == 'S' || (pr->arg.len == l && c == 's'))
		return (handle_sm(pr, va_arg(pr->ap, wchar_t*)));
	if (c == 's')
		return (handle_s(pr, va_arg(pr->ap, char*)));
	if (c == 'C' || (pr->arg.len == l && c == 'c'))
		return (handle_cm(pr, va_arg(pr->ap, wint_t)));
	if (c == 'c')
		return (handle_c(pr, (char)va_arg(pr->ap, int)));
	if (c == '%')
		return (handle_c(pr, '%'));
	return (check_unsigned_integers(pr, c));
}

int			check_specifier(t_printf *pr, char c)
{
	if (pr->arg.len == hh && (c == 'd' || c == 'i'))
		return (handle_decimal(pr, (signed char)va_arg(pr->ap, int)));
	if (pr->arg.len == h && (c == 'd' || c == 'i'))
		return (handle_decimal(pr, (short int)va_arg(pr->ap, int)));
	if ((pr->arg.len == l && (c == 'd' || c == 'i')) || c == 'D')
		return (handle_decimal(pr, (long long)va_arg(pr->ap, long int)));
	if (pr->arg.len == ll && (c == 'd' || c == 'i'))
		return (handle_decimal(pr, (long long)va_arg(pr->ap, long long int)));
	if (pr->arg.len == j && (c == 'd' || c == 'i'))
		return (handle_decimal(pr, (long long)va_arg(pr->ap, intmax_t)));
	if (pr->arg.len == z && (c == 'd' || c == 'i'))
		return (handle_decimal(pr, (long long)va_arg(pr->ap, size_t)));
	if (c == 'd' || c == 'i')
		return (handle_decimal(pr, (long long)va_arg(pr->ap, int)));
	if (c == 'p')
		return (handle_p(pr, (long long)va_arg(pr->ap, void*)));
	return (check_chars_strings(pr, c));
}
