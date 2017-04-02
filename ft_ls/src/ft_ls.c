/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 16:35:39 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/12 18:58:41 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fill_the_buf(t_folder **fd)
{
	t_folder	*aux;

	aux = *fd;
	while (aux != NULL)
	{
		aux->buf = (struct stat*)malloc(sizeof(struct stat));
		aux->special = 0;
		aux->link = 0;
		lstat(aux->path, aux->buf);
		aux = aux->next;
	}
}

void	ls_check_a(t_ls *ls, t_folder *aux)
{
	while (aux != NULL)
	{
		if (check_inv_and_a(aux, ls))
			aff_name(ls, aux, 1);
		aux = aux->next;
	}
}

void	ls_no_attr(t_ls *ls, t_folder *fd)
{
	while (fd != NULL)
	{
		if (ls->ok > 1)
		{
			ft_putstr(fd->name);
			ft_putendl(":");
		}
		if (ls->l == 1)
			ls_l(ls, fd->rec, 0);
		else
			ls_check_a(ls, fd->rec);
		if (ls->r_m == 1)
			ls_r_m(ls, fd->rec, fd->name);
		if (fd->next)
			ft_putstr("\n");
		fd = fd->next;
	}
}

int		main(int argc, char **argv)
{
	t_ls	*ls;

	ls = (t_ls*)malloc(sizeof(t_ls));
	ls->buf = (struct stat*)malloc(sizeof(struct stat));
	ls = check_flags(ls, argv);
	argv = sort_params(ls->index, argc, argv);
	ls = get_dirs(ls, argv);
	if (ls->index == 1 || (ls->ff && !ls->dd))
	{
		if (!ls->d)
			create_node(&(ls->fd), ".");
		else
			create_node(&(ls->file), ".");
	}
	gem_to_folder(ls, &(ls->fd));
	merge_sort(ls, &(ls->file));
	merge_sort(ls, &(ls->fd));
	put_file_name(ls, ls->file);
	ls_no_attr(ls, ls->fd);
	free(ls->buf);
	return (0);
}
