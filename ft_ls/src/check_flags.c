/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:43:33 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/12 18:54:28 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*fututi_normineta(t_ls *ls)
{
	ls->p = 1;
	ls->fm = 0;
	return (ls);
}

t_ls	*checker(t_ls *ls, char c)
{
	if (c == 'l')
		ls->l = 1;
	else if (c == 'R')
		ls->r_m = 1;
	else if (c == 'a')
		ls->a = 1;
	else if (c == 'r')
		ls->r = 1;
	else if (c == 't')
		ls->t = 1;
	else if (c == '1')
		ls->l = 0;
	else if (c == '-')
		ls->hueta++;
	else if (c == 'A')
		ls->am = 1;
	else if (c == 'd')
		ls->d = 1;
	else if (c == 'p')
		ls = fututi_normineta(ls);
	else
		ls = checker_aux(ls, c);
	return (ls);
}

t_ls	*parse_flags(t_ls *ls, char **argv, int *ok)
{
	int j;

	j = 1;
	while (argv[ls->index][j] != 0)
	{
		ls = checker(ls, argv[ls->index][j]);
		if (ls->hueta == 1 && j == 1 && !argv[ls->index][j + 1])
		{
			*ok = 1;
			break ;
		}
		if (ls->hueta >= 1 && j != 1)
		{
			print_error_flag('-');
			exit(42);
		}
		j++;
	}
	return (ls);
}

t_ls	*init_flags(t_ls *ls)
{
	ls->r_m = 0;
	ls->l = 0;
	ls->a = 0;
	ls->r = 0;
	ls->t = 0;
	ls->p = 0;
	ls->g = 0;
	ls->o = 0;
	ls->f = 0;
	ls->fm = 0;
	ls->tm = 0;
	ls->hueta = 0;
	ls->ff = 0;
	ls->am = 0;
	ls->d = 0;
	ls->index = 1;
	return (ls);
}

t_ls	*check_flags(t_ls *ls, char **argv)
{
	int		ok;

	ok = 0;
	ls = init_flags(ls);
	while (argv[ls->index] && ok == 0)
	{
		if (argv[ls->index][0] != '-')
			break ;
		ls->ff = 1;
		ls = parse_flags(ls, argv, &ok);
		if (ft_strlen(argv[ls->index]) > 1)
			ls->index++;
		else
			break ;
	}
	return (ls);
}
