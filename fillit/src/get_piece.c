/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:24:00 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/11 10:24:03 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**get_piece(int fd)
{
	char	**piece;
	int		index;

	piece = (char**)malloc(sizeof(char*) * 4);
	index = 0;
	while (index < 4)
	{
		if (ft_get_next_line(fd, piece + index) < 1)
			print_message_and_exit("error", 2);
		index++;
	}
	return (piece);
}
