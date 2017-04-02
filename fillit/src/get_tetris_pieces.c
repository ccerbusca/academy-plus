/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetris_pieces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:24:32 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/11 10:24:35 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*get_tetris_pieces(char *filename)
{
	t_tetris	*tetriminos;
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_message_and_exit("error", 2);
	tetriminos = NULL;
	get_tetriminos(&tetriminos, fd);
	return (tetriminos);
}
