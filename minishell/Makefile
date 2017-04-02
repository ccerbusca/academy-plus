# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccerbusc <ccerbusc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 00:05:04 by ccerbusc          #+#    #+#              #
#    Updated: 2017/04/02 17:11:44 by ccerbusc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc
NAME = minishell
OFLAGS := -I include/ -I libft/include -Wall -Werror -Wextra -g
FLAGS := $(OFLAGS) -Llibft -lft -o
_SRC = minishell.c
SRC = $(patsubst %.c, src/%.c, $(_SRC))
OBJ = $(patsubst %.c, obj/%.o, $(_SRC))

all: $(NAME)

obj:
	@mkdir -p $@

$(OBJ): | obj

libft/libft.a:
	@make -C libft

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
