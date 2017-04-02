# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 00:05:04 by ccerbusc          #+#    #+#              #
#    Updated: 2017/03/23 17:20:33 by ccerbusc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc
NAME = lem_in
OFLAGS := -I include/ -I. -Wall -Werror -Wextra -g
FLAGS := $(OFLAGS) -Llibft -lft -o
_SRC = lem_in.c utils.c utils2.c read_graph.c list_manipulate.c solve.c
SRC = $(patsubst %.c, src/%.c, $(_SRC))
OBJ = $(patsubst %.c, obj/%.o, $(_SRC))

all: $(NAME)

obj:
	@mkdir -p $@

$(OBJ): | obj

libft/libft.a:
	make -C libft

obj/%.o: src/%.c
	$(CC) $(OFLAGS) -c $< -o $@

$(NAME): libft/libft.a $(OBJ)
	$(CC) $(OBJ) $(FLAGS) $(NAME)

clean:
	/bin/rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all
