/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 09:04:36 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/20 17:39:27 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"
# include <wchar.h>
# include <stdint.h>

typedef enum	e_length
{
	no,
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_length;

typedef struct	s_arg
{
	t_length	len;
	int			left;
	int			semn;
	int			prefix;
	int			zero;
	int			blank;
	int			width;
	int			precision;
	int			nothing;
}				t_arg;

typedef struct	s_printf
{
	va_list		ap;
	t_arg		arg;
}				t_printf;

int				ft_printf(const char *restrict str, ...);
int				go(t_printf *pr, char *str);
int				check_arguments(t_printf *pr, char **str);
int				check_specifier(t_printf *pr, char c);

void			print_string(t_printf *pr, char **str, int type);
void			apply_width(t_printf *pr, char **str, int type);
void			apply_prefix(t_printf *pr, char **str, int type);
void			apply_sign(t_printf *pr, char **str);
void			apply_precision(t_printf *pr, char **str, int type);

int				print_strings_chars(t_printf *pr, char *str, int len);
int				print_wstrings_wchars(t_printf *pr, wchar_t *str, int length);
int				wchar_calc_precision(wchar_t *str, int n);

t_printf		*check_precision(t_printf *pr, char **str);
int				is_length_modifier(t_printf **pr, char **str);
t_printf		*check_length_modifiers(t_printf *pr, char **str);
t_printf		*check_flags(t_printf *pr, char **str);
t_printf		*check_sub_specifiers(t_printf *pr, char **str);

int				check_specifier(t_printf *pr, char c);
int				check_chars_strings(t_printf *pr, char c);
int				check_unsigned_integers(t_printf *pr, char c);
int				check_unsigned_integers2(t_printf *pr,
			int handle(t_printf *pr, unsigned long long));

int				handle_s(t_printf *pr, char *str);
int				handle_sm(t_printf *pr, wchar_t *str);
int				handle_c(t_printf *pr, char c);
int				handle_nothing(t_printf *pr, char c);
int				handle_cm(t_printf *pr, wchar_t c);
int				handle_p(t_printf *pr, long long ad);
int				handle_decimal(t_printf *pr, long long nr);
int				handle_u(t_printf *pr, unsigned long long nr);
int				handle_o(t_printf *pr, unsigned long long nr);
int				handle_x(t_printf *pr, unsigned long long nr);
int				handle_xm(t_printf *pr, unsigned long long nr);

void			init_flags(t_arg *ptr);
int				check_if_sub_specifier(char c);
t_printf		*handle_wildcard(t_printf *pr);
t_printf		*norminette_ftw(t_printf *pr, int length, int *len, char *c);
char			*no_leak_strjoin(char *s1, char *s2, int f1, int f2);

#endif
