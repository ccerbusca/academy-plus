/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_flag_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:42:00 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/12 19:01:28 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		calc_stdblocks(t_ls *ls, t_folder *fd)
{
	int		blocks;

	blocks = 0;
	while (fd)
	{
		if (check_inv_and_a(fd, ls) || ls->d)
			blocks += fd->buf->st_blocks;
		fd = fd->next;
	}
	ft_putstr("total ");
	ft_putnbr(blocks);
	ft_putendl("");
}

void		entry_type_chr(t_folder **fd, t_ls **ls)
{
	if (S_IFBLK == ((*fd)->buf->st_mode & S_IFMT))
	{
		(*fd)->special = 1;
		(*ls)->special = 1;
		ft_putchar('b');
	}
	else if (S_IFCHR == ((*fd)->buf->st_mode & S_IFMT))
	{
		(*fd)->special = 1;
		(*ls)->special = 1;
		ft_putchar('c');
	}
	else if (S_IFLNK == ((*fd)->buf->st_mode & S_IFMT))
	{
		(*fd)->link = 1;
		ft_putchar('l');
	}
	else if (S_IFSOCK == ((*fd)->buf->st_mode & S_IFMT))
		ft_putchar('s');
	else if (S_IFIFO == ((*fd)->buf->st_mode & S_IFMT))
		ft_putchar('p');
	else if (S_IFDIR == ((*fd)->buf->st_mode & S_IFMT))
		ft_putchar('d');
	else
		ft_putchar('-');
}

void		put_perm(t_folder *fd)
{
	if (S_IRUSR & fd->buf->st_mode)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (S_IWUSR & fd->buf->st_mode)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (!(S_IXUSR & fd->buf->st_mode) && S_ISUID & fd->buf->st_mode)
		ft_putchar('S');
	else if (S_IXUSR & fd->buf->st_mode && S_ISUID & fd->buf->st_mode)
		ft_putchar('s');
	else if (S_IXUSR & fd->buf->st_mode)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void		put_perm_gr(t_folder *fd)
{
	if (S_IRGRP & fd->buf->st_mode)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (S_IWGRP & fd->buf->st_mode)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (!(S_IXGRP & fd->buf->st_mode) && S_ISGID & fd->buf->st_mode)
		ft_putchar('S');
	else if (S_IXGRP & fd->buf->st_mode && S_ISGID & fd->buf->st_mode)
		ft_putchar('s');
	else if (S_IXGRP & fd->buf->st_mode)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void		put_perm_oth(t_folder *fd)
{
	if (S_IROTH & fd->buf->st_mode)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (S_IWOTH & fd->buf->st_mode)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (!(S_IXOTH & fd->buf->st_mode) && S_ISVTX & fd->buf->st_mode)
		ft_putchar('T');
	else if (S_IXOTH & fd->buf->st_mode && S_ISVTX & fd->buf->st_mode)
		ft_putchar('t');
	else if (S_IXOTH & fd->buf->st_mode)
		ft_putchar('x');
	else
		ft_putchar('-');
	put_xattr(fd);
}
