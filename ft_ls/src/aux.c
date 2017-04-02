/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 16:50:29 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/12 18:58:23 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	put_file_name(t_ls *ls, t_folder *file)
{
	int ok;

	ok = 1;
	while (file != NULL)
	{
		if (ls->l == 1)
			ls_l(ls, file, 1);
		else
			aff_name(ls, file, 1);
		ok = 0;
		file = file->next;
	}
	if (ls->fd != NULL && ok == 0)
		ft_putendl("");
}

char	*extract_name(char *path)
{
	char	*s;

	s = ft_strrchr(path, '/');
	if (!s)
		return (ft_strdup(path));
	else
		return (ft_strdup(s + 1));
}

int		file_exists(char *file)
{
	struct stat	*buffer;

	buffer = (struct stat*)malloc(sizeof(struct stat));
	return (lstat(file, buffer) == 0);
}

void	put_ws(int ws)
{
	int	i;

	i = 0;
	while (i < ws)
	{
		ft_putchar(' ');
		i++;
	}
}

int		check_inv_and_a(t_folder *fd, t_ls *ls)
{
	if (fd->name[0] == '.')
	{
		if (ls->a)
			ls->am = 0;
		if (ls->am)
			if (ft_strcmp(fd->name, ".") != 0 && ft_strcmp(fd->name, "..") != 0)
				return (1);
		if (ls->a == 1)
			return (1);
		return (0);
	}
	return (1);
}
