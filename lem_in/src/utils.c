/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:23:38 by ccerbusc          #+#    #+#             */
/*   Updated: 2017/03/23 17:39:25 by ccerbusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	err(char *str)
{
	ft_putendl_fd(str, 2);
	exit(-42);
}

int		count_char(char *str, char c)
{
	int cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == c)
			cnt++;
		str++;
	}
	return (cnt);
}

char	*return_line(void)
{
	char	*str;
	int		ret;

	str = NULL;
	ret = get_next_line(0, &str);
	if (ret == -1)
	{
		err("ERROR WHILE READING");
		return (NULL);
	}
	else if (ret == 1)
		return (str);
	else
		return (NULL);
}

void	fill(int *start, int *end, int filler)
{
	while (start != end)
	{
		*start = filler;
		start++;
	}
}

void	fill_tab(t_lem *lem)
{
	char	**tab;
	int		p;
	int		q;
	int		i;

	tab = ft_strsplit(lem->line, '-');
	if (!tab || count_char(lem->line, '-') != 1)
		err("LINK INCORRECTLY SPECIFIED");
	p = get_index(lem, tab[0]);
	q = get_index(lem, tab[1]);
	if (p == -1 || q == -1)
		err("LINK IS INCORRECTLY SPECIFIED");
	lem->map[p][q] = 1;
	lem->map[q][p] = 1;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
