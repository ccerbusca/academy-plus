/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:53:26 by vdruta            #+#    #+#             */
/*   Updated: 2016/01/11 10:06:51 by vdruta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>

typedef struct		s_tetris
{
	unsigned char	*coordinates;
	char			letter;
	char			clone;
	struct s_tetris	*next;
}					t_tetris;

void				print_message_and_exit(char *message, int output);
void				print_map_and_exit(char *str, int output);
t_tetris			*get_tetris_pieces(char *filename);
void				get_tetriminos(t_tetris **tetriminos, int fd);
char				**get_piece(int fd);
unsigned char		*get_coordinates(char **piece);
void				adjust_coordinates(unsigned char *coordinates);
void				add_piece_to_list(t_tetris **tetriminos,
		unsigned char *coordinates, char letter);
void				fillit(t_tetris *list);
void				change_coordinates(t_tetris *list, unsigned char size);
void				increment_coordinates(t_tetris *list, unsigned char size);
void				backtrack(t_tetris *tetriminos, char *map);
#endif
