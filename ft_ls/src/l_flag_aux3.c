/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_flag_aux3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:42:00 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/06/09 17:33:10 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		put_size(t_folder *fd, t_ls *ls)
{
	int		nr;
	int		size;

	nr = fd->buf->st_size;
	size = ft_nrlen(nr);
	put_ws(ls->max_size - size);
	ft_putnbr(nr);
	ft_putstr(" ");
}

void		put_nlink(t_folder *fd, t_ls *ls)
{
	int nr;

	nr = fd->buf->st_nlink;
	put_ws(1 + ls->max_nlink - ft_nrlen(nr));
	ft_putnbr(nr);
	ft_putchar(' ');
}

void		put_symlink(t_folder *fd)
{
	char *str;

	str = ft_strnew(1024);
	ft_putstr(" -> ");
	readlink(fd->path, str, 1024);
	ft_putendl(str);
}

void		put_mm(t_folder *fd, t_ls *ls, int ok)
{
	if (ok == 1)
	{
		put_ws(3 + ls->max_major - ft_nrlen(major(fd->buf->st_rdev)));
		ft_putnbr(major(fd->buf->st_rdev));
		ft_putchar(',');
		put_ws(1 + ls->max_minor - ft_nrlen(minor(fd->buf->st_rdev)));
		ft_putnbr(minor(fd->buf->st_rdev));
	}
	else
	{
		put_ws(5 + ls->max_minor + ls->max_major - ft_nrlen(fd->buf->st_size));
		ft_putnbr(fd->buf->st_size);
	}
	ft_putchar(' ');
}

int			count_files(t_ls *ls, t_folder *fd)
{
	int nr;

	nr = 0;
	while (fd)
	{
		if (check_inv_and_a(fd, ls) || ls->d)
			nr++;
		fd = fd->next;
	}
	return (nr);
}
