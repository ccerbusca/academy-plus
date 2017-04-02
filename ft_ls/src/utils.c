/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:08:06 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/12 19:17:53 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		swap_params(char **str1, char **str2)
{
	char	*aux;

	aux = ft_strdup(*str1);
	*str1 = ft_strdup(*str2);
	*str2 = ft_strdup(aux);
	free(aux);
}

void		create_node(t_folder **fd, char *name)
{
	t_folder	*aux;

	aux = *fd;
	if (*fd == NULL)
	{
		*fd = (t_folder*)malloc(sizeof(t_folder));
		(*fd)->name = ft_strdup(name);
		(*fd)->path = ft_strdup(name);
		(*fd)->next = NULL;
	}
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = (t_folder*)malloc(sizeof(t_folder));
		aux->next->name = ft_strdup(name);
		aux->next->path = ft_strdup(name);
		aux->next->next = NULL;
	}
}

void		aff_name(t_ls *ls, t_folder *fd, int endl)
{
	lstat(fd->path, ls->buf);
	ft_putstr(fd->name);
	if (S_ISDIR(ls->buf->st_mode) && (ls->p || ls->fm))
		ft_putchar('/');
	else if (ls->fm)
	{
		if (S_ISLNK(ls->buf->st_mode))
			ft_putchar('@');
		else if (S_ISSOCK(ls->buf->st_mode))
			ft_putchar('=');
		else if (S_ISWHT(ls->buf->st_mode))
			ft_putchar('%');
		else if (S_ISFIFO(ls->buf->st_mode))
			ft_putchar('|');
		else if (S_ISREG(ls->buf->st_mode) && (ls->buf->st_mode & 0111))
			ft_putchar('*');
	}
	if (endl)
		ft_putchar('\n');
}

void		put_xattr(t_folder *fd)
{
	acl_t			acl;
	acl_entry_t		acl_entry;

	acl = acl_get_link_np(fd->path, ACL_TYPE_EXTENDED);
	if (acl && (acl_get_entry(acl, ACL_FIRST_ENTRY, &acl_entry) == -1))
		ft_putchar(' ');
	else if ((fd->link == 0
			&& listxattr(fd->path, NULL, 0, 0) > 0)
		|| (fd->link == 1
			&& listxattr(fd->path, NULL, 0, XATTR_NOFOLLOW) > 0))
		ft_putchar('@');
	else if (acl != NULL)
		ft_putchar('+');
	else
		ft_putchar(' ');
}
