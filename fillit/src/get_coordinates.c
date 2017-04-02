/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:23:46 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/11 10:23:48 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			save_coordinates(unsigned char *coordinates, int row,
		int column)
{
	int		length;

	length = 0;
	while (coordinates[length] != 4)
		length++;
	if (length >= 8)
		print_message_and_exit("error", 2);
	coordinates[length] = row;
	coordinates[length + 1] = column;
}

void			get_coordinates_row(char **piece, int row,
		unsigned char *coordinates, int *neighbours)
{
	int		column;

	column = 0;
	while (column < 4)
	{
		if (piece[row][column] != '.' && piece[row][column] != '#')
			print_message_and_exit("error", 2);
		if (piece[row][column] == '#')
		{
			if (coordinates[7] != 4)
				print_message_and_exit("error", 2);
			save_coordinates(coordinates, column, row);
			if (column != 3 && piece[row][column + 1] == '#')
				(*neighbours)++;
			if (row != 3 && piece[row + 1][column] == '#')
				(*neighbours)++;
		}
		column++;
	}
	if (piece[row][column] != '\0')
		print_message_and_exit("error", 2);
}

unsigned char	*get_coordinates(char **piece)
{
	unsigned char	*coordinates;
	int				neighbours;
	int				row;

	coordinates = malloc(sizeof(char) * 8);
	ft_memset(coordinates, 4, 8);
	neighbours = 0;
	row = 0;
	while (row < 4)
	{
		get_coordinates_row(piece, row, coordinates, &neighbours);
		row++;
	}
	if (neighbours < 3)
		print_message_and_exit("error", 2);
	return (coordinates);
}
