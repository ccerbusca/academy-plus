/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 15:54:26 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/01/12 19:09:08 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				compare_r(t_ls *ls, t_folder *a, t_folder *b)
{
	if (ls->t == 0)
	{
		if (ls->r == 1)
			return (ft_strcmp(a->name, b->name) > 0);
		return (ft_strcmp(a->name, b->name) < 0);
	}
	else
	{
		a->buf = (struct stat*)malloc(sizeof(struct stat));
		b->buf = (struct stat*)malloc(sizeof(struct stat));
		lstat(a->path, a->buf);
		lstat(b->path, b->buf);
		if (ls->r == 1)
			if (a->buf->st_mtimespec.tv_sec == b->buf->st_mtimespec.tv_sec)
				return (ft_strcmp(a->name, b->name) > 0);
			else
				return (a->buf->st_mtimespec.tv_sec
						< b->buf->st_mtimespec.tv_sec);
		else if (a->buf->st_mtimespec.tv_sec == b->buf->st_mtimespec.tv_sec)
			return (ft_strcmp(a->name, b->name) < 0);
		else
			return (a->buf->st_mtimespec.tv_sec > b->buf->st_mtimespec.tv_sec);
		free(a->buf);
		free(b->buf);
	}
}

t_folder		*sorted_merge(t_ls *ls, t_folder *a, t_folder *b)
{
	t_folder	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (compare_r(ls, a, b))
	{
		result = a;
		result->next = sorted_merge(ls, a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(ls, a, b->next);
	}
	return (result);
}

void			front_back_split(t_folder *source, t_folder **front,
		t_folder **back)
{
	t_folder	*fast;
	t_folder	*slow;

	if (source == NULL || source->next == NULL)
	{
		*front = source;
		*back = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = source;
		*back = slow->next;
		slow->next = NULL;
	}
}

void			merge_sort(t_ls *ls, t_folder **headref)
{
	t_folder	*head;
	t_folder	*a;
	t_folder	*b;

	head = *headref;
	if ((head == NULL) || (head->next == NULL) || ls->f)
		return ;
	front_back_split(head, &a, &b);
	merge_sort(ls, &a);
	merge_sort(ls, &b);
	*headref = sorted_merge(ls, a, b);
}

char			**sort_params(int i, int argc, char **str)
{
	int		j;

	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(str[i], str[j]) > 0)
				swap_params(&str[i], &str[j]);
			j++;
		}
		i++;
	}
	return (str);
}
