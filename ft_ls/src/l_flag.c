/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 14:51:28 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/12 19:00:20 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_l_all(t_folder *fd, t_ls *ls)
{
	entry_type_chr(&fd, &ls);
	put_perm(fd);
	put_perm_gr(fd);
	put_perm_oth(fd);
	put_nlink(fd, ls);
	put_name(fd, ls);
	if (ls->special)
	{
		if (fd->special)
			put_mm(fd, ls, 1);
		else
			put_mm(fd, ls, 0);
	}
	else
		put_size(fd, ls);
	put_time(fd, ls->tm);
	aff_name(ls, fd, 0);
	if (fd->link == 1)
		put_symlink(fd);
	else
		ft_putendl("");
}

t_ls		*calc_max_check2(t_folder *fd, t_ls *ls)
{
	if ((ls->aux2 = getgrgid(fd->buf->st_gid)))
	{
		if ((int)ft_strlen(ls->aux2->gr_name) > ls->max_group)
			if (check_inv_and_a(fd, ls) || ls->d)
				ls->max_group = ft_strlen(ls->aux2->gr_name);
	}
	else if (check_inv_and_a(fd, ls) || ls->d)
		ls->max_group = ft_nrlen(fd->buf->st_gid);
	if (ft_nrlen(minor(fd->buf->st_rdev)) > ls->max_minor)
		if (check_inv_and_a(fd, ls) || ls->d)
			ls->max_minor = ft_nrlen(minor(fd->buf->st_rdev));
	if (ft_nrlen(major(fd->buf->st_rdev)) > ls->max_major)
		if (check_inv_and_a(fd, ls) || ls->d)
			ls->max_major = ft_nrlen(major(fd->buf->st_rdev));
	return (ls);
}

t_ls		*calc_max_check(t_folder *fd, t_ls *ls)
{
	while (fd)
	{
		if (ft_nrlen(fd->buf->st_size) > ls->max_size)
			if (check_inv_and_a(fd, ls) || ls->d)
				ls->max_size = ft_nrlen(fd->buf->st_size);
		if (ft_nrlen(fd->buf->st_nlink) > ls->max_nlink)
			if (check_inv_and_a(fd, ls) || ls->d)
				ls->max_nlink = ft_nrlen(fd->buf->st_nlink);
		if ((ls->aux = getpwuid(fd->buf->st_uid)))
		{
			if ((int)ft_strlen(ls->aux->pw_name) > ls->max_user)
				if (check_inv_and_a(fd, ls) || ls->d)
					ls->max_user = ft_strlen(ls->aux->pw_name);
		}
		else if (check_inv_and_a(fd, ls) || ls->d)
			ls->max_user = ft_nrlen(fd->buf->st_uid);
		ls = calc_max_check2(fd, ls);
		fd = fd->next;
	}
	return (ls);
}

t_ls		*len_max_size(t_folder *fd, t_ls *ls)
{
	ls->max_size = 0;
	ls->max_nlink = 0;
	ls->max_minor = 0;
	ls->max_major = 0;
	ls->max_user = 0;
	ls->max_group = 0;
	ls = calc_max_check(fd, ls);
	return (ls);
}

void		ls_l(t_ls *ls, t_folder *fd, int file)
{
	ls->special = 0;
	fill_the_buf(&fd);
	if (file == 0 && count_files(ls, fd))
		calc_stdblocks(ls, fd);
	ls = len_max_size(fd, ls);
	while (fd)
	{
		if (check_inv_and_a(fd, ls) || ls->d)
			ls_l_all(fd, ls);
		if (file)
			return ;
		fd = fd->next;
	}
}
