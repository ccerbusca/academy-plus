/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:03:08 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/19 16:05:46 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_error_flag(char c)
{
	char *str;

	str = ft_strnew(2);
	str[0] = c;
	str[1] = '\0';
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_putendl_fd("usage: ls [-lRartAd] [file ...]", 2);
	exit(0);
}

t_ls		*checker_aux(t_ls *ls, char c)
{
	if (c == 'f')
	{
		ls->a = 1;
		ls->f = 1;
	}
	else if (c == 'T')
		ls->tm = 1;
	else if (c == 'F')
	{
		ls->fm = 1;
		ls->p = 1;
	}
	else if (c == 'g')
	{
		ls->l = 1;
		ls->g = 1;
	}
	else if (c == 'o')
	{
		ls->l = 1;
		ls->o = 1;
	}
	else
		print_error_flag(c);
	return (ls);
}

char		*get_hour(char *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (k != 2)
	{
		if (str[i] == ':')
			k++;
		i++;
	}
	str[i - 1] = '\0';
	return (str);
}

void		get_time(char *str, t_timp *t, int tm)
{
	char	**aux;

	aux = ft_split(str);
	t->month = aux[1];
	t->day = aux[2];
	t->hour = tm ? aux[3] : get_hour(aux[3]);
	t->year = aux[4];
}

int			check_time(time_t sec)
{
	time_t	now;

	time(&now);
	if (sec > (now + SIXMONTHS) || sec < (now - SIXMONTHS))
		return (0);
	return (1);
}
