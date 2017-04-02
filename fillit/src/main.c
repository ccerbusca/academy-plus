/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:24:45 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/11 10:24:46 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tetris	*list;

	if (ac == 2)
	{
		list = get_tetris_pieces(av[1]);
		fillit(list);
	}
	else
		print_message_and_exit("usage: ./fillit source_file", 1);
	return (0);
}
