/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_m_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 15:52:47 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/12 18:58:58 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	gem_to_folder2(t_folder **fd)
{
	t_folder	*aux;

	aux = *fd;
	aux->rec = dir_reading(aux);
}

void	annex_path(t_folder **fd, char *path)
{
	t_folder	*aux;

	aux = *fd;
	while (aux)
	{
		aux->path = ft_strjoin(path, "/");
		aux->path = ft_strjoin(aux->path, aux->name);
		aux = aux->next;
	}
}

void	afficher(t_ls *ls, t_folder *fd, char *str)
{
	str = ft_strjoin(str, "/");
	fd->path = ft_strjoin(str, fd->name);
	ft_putendl("");
	ft_putstr(fd->path);
	ft_putendl(":");
	gem_to_folder2(&fd);
	annex_path(&(fd->rec), fd->path);
	merge_sort(ls, &(fd->rec));
	if (ls->l == 0)
		ls_check_a(ls, fd->rec);
	else
		ls_l(ls, fd->rec, 0);
	ls_r_m(ls, fd->rec, fd->path);
}

void	ls_r_m(t_ls *ls, t_folder *fd, char *str)
{
	char	*check;

	while (fd)
	{
		check = ft_strjoin(str, "/");
		check = ft_strjoin(check, fd->name);
		fd->buf = (struct stat*)malloc(sizeof(struct stat));
		if (!lstat(check, fd->buf) && S_ISDIR(fd->buf->st_mode)
				&& ft_strcmp(fd->name, ".") != 0
				&& ft_strcmp(fd->name, "..") != 0)
		{
			if (check_inv_and_a(fd, ls))
				afficher(ls, fd, str);
		}
		free(fd->buf);
		fd = fd->next;
	}
}
