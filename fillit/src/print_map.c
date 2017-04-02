/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:25:14 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/11 10:25:16 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != 0)
	{
		ft_putendl(map[i]);
		i++;
	}
}

void	print_map_temp(char **map)
{
	int i;

	i = 0;
	while (map[i][0] != '\0')
	{
		ft_putendl(map[i]);
		i++;
	}
}
