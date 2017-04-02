/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:24:15 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/11 10:24:17 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_tetriminos(t_tetris **tetriminos, int fd)
{
	char			**piece;
	char			*line;
	unsigned char	*coordinates;
	char			letter;
	int				boolean;

	boolean = 1;
	letter = 'A';
	while (boolean == 1 && letter <= 'Z')
	{
		piece = get_piece(fd);
		coordinates = get_coordinates(piece);
		adjust_coordinates(coordinates);
		add_piece_to_list(tetriminos, coordinates, letter);
		if (ft_get_next_line(fd, &line) == 0)
			boolean = 0;
		else if (!ft_strequ(line, ""))
			print_message_and_exit("error", 2);
		letter++;
	}
	if (ft_get_next_line(fd, &line) > 0)
		print_message_and_exit("error", 2);
}
