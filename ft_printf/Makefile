# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/24 16:43:17 by ccerbusc          #+#    #+#              #
#    Updated: 2017/01/27 17:56:28 by ccerbusc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra -Iinclude -c

NAME = libftprintf.a

CC = @gcc

_SRC = check_specifiers.c check_sub_specifiers.c ft_printf.c handle_wsc.c \
	   handle_diu.c handle_scp.c handle_xoxo.c print_numbers.c utils.c

SRC = $(patsubst %.c, src/%.c, $(_SRC))

OBJ = $(patsubst src/%.c, obj/%.o, $(SRC)) 

all: $(NAME)

$(OBJ): | obj

obj:
	@mkdir -p $@

obj/%.o: src/%.c
	$(CC) $(FLAGS) $< -o $@

libft/libft.a:
	@make -C libft/

$(NAME): libft/libft.a $(OBJ)
	@cp $< $(NAME)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
