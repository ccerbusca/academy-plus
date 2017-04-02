# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 00:05:04 by ccerbusc          #+#    #+#              #
#    Updated: 2017/02/09 10:46:53 by ccerbusc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc
NAME1 = checker
NAME2 = push_swap
FLAGS := -Wall -Werror -Wextra -Iinclude
SRC = checker.c push_swap.c
COMMON = utils.c utils2.c fill_stack.c
COMMON_OBJ = $(patsubst %.c, obj/%.o, $(COMMON))
OBJ1 = $(COMMON_OBJ) obj/checker.o obj/handle_inst.o
OBJ2 = $(COMMON_OBJ) obj/push_swap.o

all: $(NAME1) $(NAME2)

obj:
	@mkdir -p $@

$(OBJ1): | obj

$(OBJ2): | obj

libft/libft.a:
	make -C libft

obj/%.o: src/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME1): libft/libft.a $(OBJ1)
	$(CC) $(FLAGS) $(OBJ1) -Llibft -lft -o $(NAME1)

$(NAME2): libft/libft.a $(OBJ2)
	$(CC) $(FLAGS) $(OBJ2) -Llibft -lft -o $(NAME2)

clean:
	/bin/rm -rf $(OBJ1) $(OBJ2)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME1) $(NAME2)
	make -C libft fclean

re: fclean all
