/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:29:14 by ccerbusc          #+#    #+#             */
/*   Updated: 2016/03/05 20:25:03 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_scale		*get_coord(char **aux, int col)
{
	int		i;
	t_scale	*tab;

	i = 0;
	tab = (t_scale*)malloc(sizeof(t_scale) * col);
	while (aux[i])
	{
		tab[i].z = ft_atoi(aux[i]);
		i++;
	}
	return (tab);
}

t_scale		**convert(char *s, t_matrix sizes)
{
	char	*str;
	char	**aux;
	t_scale	**tab;
	int		i;
	int		fd;

	fd = open_file(s);
	i = 0;
	tab = (t_scale**)malloc(sizeof(t_scale*) * (sizes.row));
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

	fd = open_file(s);
	str = NULL;
	get_next_line(fd, &str);
	k.col = get_col(str);
	k.row = 1;
	while (get_next_line(fd, &str) == 1)
		k.row++;
	k.sp = 0.75 * (WIDTH / (k.row * 0.5 + k.col * 0.86));
	close(fd);
	return (k);
}
