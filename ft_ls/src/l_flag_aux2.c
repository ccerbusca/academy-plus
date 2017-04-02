/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_flag_aux2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:03:37 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/19 16:06:01 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		put_owner(t_folder *fd, t_ls *ls)
{
	struct passwd	*aux;

	if ((aux = getpwuid(fd->buf->st_uid)))
	{
		ft_putstr(aux->pw_name);
		put_ws(2 * !ls->o + ls->max_user - ft_strlen(aux->pw_name));
	}
	else
	{
		ft_putstr(ft_itoa(fd->buf->st_uid));
		put_ws(2 * !ls->o + ls->max_user - ft_nrlen(fd->buf->st_uid));
	}
}

void		put_group(t_folder *fd, t_ls *ls)
{
	struct group	*aux2;

	if ((aux2 = getgrgid(fd->buf->st_gid)))
	{
		ft_putstr(aux2->gr_name);
		put_ws(ls->max_group - ft_strlen(aux2->gr_name));
	}
	else
	{
		ft_putstr(ft_itoa(fd->buf->st_gid));
		put_ws(ls->max_group - ft_nrlen(fd->buf->st_gid));
	}
}

void		put_name(t_folder *fd, t_ls *ls)
{
	if (ls->g == 0)
		put_owner(fd, ls);
	if (ls->o == 0)
		put_group(fd, ls);
	put_ws(2);
}

void		put_time_aux(t_folder *fd, t_timp t, int tm)
{
	if (!tm)
	{
		if (check_time(fd->buf->st_mtimespec.tv_sec))
			ft_putstr(t.hour);
		else
		{
			ft_putstr(" ");
			ft_putstr(t.year);
		}
	}
	else
	{
		ft_putstr(t.hour);
		ft_putstr(" ");
		ft_putstr(t.year);
	}
}

void		put_time(t_folder *fd, int tm)
{
	char	*str;
	t_timp	t;

	str = ctime(&fd->buf->st_mtimespec.tv_sec);
	get_time(str, &t, tm);
	ft_putstr(t.month);
	ft_putstr(" ");
	if (ft_strlen(t.day) == 1)
	{
		ft_putstr(" ");
		ft_putstr(t.day);
	}
	else
		ft_putstr(t.day);
	ft_putstr(" ");
	put_time_aux(fd, t, tm);
	ft_putstr(" ");
}
