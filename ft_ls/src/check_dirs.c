/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 16:53:40 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/12 19:20:39 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_folder	*dir_reading(t_folder *fd)
{
	DIR				*dir;
	t_folder		*gem;
	struct dirent	*data;

	gem = NULL;
	dir = NULL;
	dir = opendir(fd->path);
	fd->buf = (struct stat*)malloc(sizeof(struct stat));
	if (!dir)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(extract_name(fd->name), 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else
		while ((data = readdir(dir)) != NULL)
			create_node(&gem, data->d_name);
	if (dir)
		closedir(dir);
	return (gem);
}

void		print_error_folder(char *str)
{
	ft_putstr_fd("ls: ", 2);
	if (ft_strlen(str) == 0)
		ft_putstr_fd("fts_open", 2);
	else
		ft_putstr_fd(str, 2);
	ft_putendl_fd(": No such file or directory", 2);
	if (ft_strlen(str) == 0)
		exit(42);
}

t_ls		*get_dirs_aux(t_ls *ls, char **argv)
{
	ls->str = ft_strnew(1024);
	if (lstat(argv[ls->index], ls->buf) == 0
			&& S_ISLNK(ls->buf->st_mode))
	{
		readlink(argv[ls->index], ls->str, 1024);
		if (opendir(ls->str) != NULL)
			if (!ls->d)
				create_node(&(ls->fd), argv[ls->index]);
			else
				create_node(&(ls->file), argv[ls->index]);
		else
			create_node(&(ls->file), argv[ls->index]);
	}
	else if (file_exists(argv[ls->index]) && !S_ISDIR(ls->buf->st_mode))
		create_node(&(ls->file), argv[ls->index]);
	else if (!file_exists(argv[ls->index]))
		print_error_folder(argv[ls->index]);
	else if (!ls->d)
		create_node(&(ls->fd), argv[ls->index]);
	else
		create_node(&(ls->file), argv[ls->index]);
	free(ls->str);
	return (ls);
}

t_ls		*get_dirs(t_ls *ls, char **argv)
{
	ls->ok = 0;
	ls->dd = 0;
	while (argv[ls->index])
	{
		ls->dd = 1;
		ls->ok++;
		ls = get_dirs_aux(ls, argv);
		ls->index++;
	}
	return (ls);
}

void		gem_to_folder(t_ls *ls, t_folder **fd)
{
	t_folder	*aux;

	aux = *fd;
	while (aux != NULL)
	{
		aux->rec = dir_reading(aux);
		annex_path(&(aux->rec), aux->path);
		merge_sort(ls, &(aux->rec));
		aux = aux->next;
	}
}
