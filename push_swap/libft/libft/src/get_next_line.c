/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:44:19 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/03/05 19:49:53 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		read_file(int const fd, char **aux)
{
	char	*buff;
	int		k;

	if (!(buff = (char*)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	k = read(fd, buff, BUFF_SIZE);
	if (k > 0)
	{
		buff[k] = 0;
		*aux = ft_strjoin(*aux, buff);
	}
	return (k);
}

static	t_gnl	*create_node(t_gnl **list, int fd)
{
	t_gnl	*ptr;
	t_gnl	*start;

	ptr = (t_gnl*)malloc(sizeof(*ptr));
	ptr->fdd = fd;
	ptr->str = ft_strnew(10);
	ptr->next = NULL;
	start = *list;
	if (start == NULL)
		*list = ptr;
	else
	{
		while (start->next)
			start = start->next;
		start->next = ptr;
	}
	return (ptr);
}

static	t_gnl	*find_fd2(t_gnl **aux, int fd)
{
	t_gnl	*aux1;
	t_gnl	*aux2;

	aux1 = *aux;
	aux2 = NULL;
	while (aux1)
	{
		if (aux1->fdd == fd)
		{
			aux2 = aux1;
			break ;
		}
		aux1 = aux1->next;
	}
	if (aux2 == NULL)
		aux2 = create_node(aux, fd);
	return (aux2);
}

char			*get_line(t_gnl **aux2, char *endl)
{
	char	*kappa;

	kappa = ft_strsub((*aux2)->str, 0,
			ft_strlen((*aux2)->str) - ft_strlen(endl));
	(*aux2)->str = ft_strdup(endl + 1);
	return (kappa);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	*aux = NULL;
	t_gnl			*aux2;
	char			*endl;
	int				i;

	if (!line || fd < 0)
		return (-1);
	aux2 = find_fd2(&aux, fd);
	endl = ft_strchr(aux2->str, '\n');
	while (endl == NULL)
	{
		i = read_file(fd, &(aux2->str));
		if (i == 0)
		{
			if (ft_strlen(aux2->str) == 0)
				return (0);
			aux2->str = ft_strjoin(aux2->str, "\n");
		}
		if (i < 0)
			return (-1);
		else
			endl = ft_strchr(aux2->str, '\n');
	}
	*line = get_line(&aux2, endl);
	return (1);
}
