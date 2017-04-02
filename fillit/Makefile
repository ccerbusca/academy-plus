# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdruta <vdruta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 10:15:42 by vdruta            #+#    #+#              #
#    Updated: 2016/01/11 10:21:54 by vdruta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = src/add_piece_to_list.c src/backtrack.c src/get_coordinates.c \
	  src/get_tetriminos.c src/main.c src/print_map.c src/adjust_coordinates.c \
	  src/fillit.c src/get_piece.c src/get_tetris_pieces.c \
	  src/manipulate_coordinates.c	src/print_message_and_exit.c

OBJ = add_piece_to_list.o backtrack.o get_coordinates.o get_tetriminos.o main.o\
	  print_map.o adjust_coordinates.o fillit.o get_piece.o get_tetris_pieces.o\
	  manipulate_coordinates.o	print_message_and_exit.o

INC = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) -I $(INC) -c $(SRC)
	gcc $(OBJ) -L libft/ -lft -o $(NAME)

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
