/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:29:14 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/03/15 19:21:22 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			open_file(char *str)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("No file ");
		ft_putendl(str);
		exit(0);
	}
	return (fd);
}

int			get_col(char *s)
{
	int		nr;

	nr = 0;
	while (*s)
	{
		if (*s != ' ')
		{
			nr++;
			while (*s != ' ' && *s)
				s++;
			s--;
		}
		s++;
	}
	return (nr);
}

int			*get_coord(char **aux, int col)
{
	int		i;
	int		*tab;

	i = 0;
	tab = (int*)malloc(sizeof(int) * col);
	while (aux[i])
	{
		tab[i] = ft_atoi(aux[i]);
		i++;
	}
	return (tab);
}

int			**convert(char *s, t_matrix sizes)
{
	char	*str;
	char	**aux;
	int		**tab;
	int		i;
	int		fd;

	fd = open_file(s);
	i = 0;
	tab = (int**)malloc(sizeof(int*) * (sizes.row));
	str = NULL;
	while (get_next_line(fd, &str) == 1)
	{
		aux = ft_split(str);
		tab[i] = get_coord(aux, sizes.col);
		i++;
	}
	close(fd);
	return (tab);
}

t_matrix	get_sizes(char *s)
{
	t_matrix	k;
	int			fd;
	char		*str;
	int			ret;

	fd = open_file(s);
	str = NULL;
	get_next_line(fd, &str);
	k.col = get_col(str);
	k.row = 1;
	while ((ret = get_next_line(fd, &str)) == 1)
	{
		if (get_col(str) != k.col)
		{
			ft_putendl("Map is invalid");
			exit(1);
		}
		k.row++;
	}
	if (ret == -1)
		exit(1);
	close(fd);
	return (k);
}
