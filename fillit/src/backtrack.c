/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:20:40 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/11 09:33:07 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place_piece(t_tetris *list, char *map, unsigned char index)
{
	if (map[index + list->coordinates[0]] != '.' ||
			map[index + list->coordinates[1]] != '.' ||
			map[index + list->coordinates[2]] != '.' ||
			map[index + list->coordinates[3]] != '.')
		return (0);
	map[index + list->coordinates[0]] = list->letter;
	map[index + list->coordinates[1]] = list->letter;
	map[index + list->coordinates[2]] = list->letter;
	map[index + list->coordinates[3]] = list->letter;
	backtrack(list->next, map);
	return (1);
}

void	erase_piece(t_tetris *list, char *map, unsigned char index)
{
	map[index + list->coordinates[0]] = '.';
	map[index + list->coordinates[1]] = '.';
	map[index + list->coordinates[2]] = '.';
	map[index + list->coordinates[3]] = '.';
}

void	backtrack(t_tetris *list, char *map)
{
	unsigned char	index;
	char			clone;

	if (!list)
		print_map_and_exit(map, 1);
	index = 0;
	clone = list->clone;
	if (clone != '\0')
	{
		while (map[index] != clone)
			index++;
		index++;
	}
	while (map[index] != '\0')
	{
		if (place_piece(list, map, index))
			erase_piece(list, map, index);
		index++;
	}
}
