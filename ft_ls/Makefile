# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/21 14:32:52 by ccerbusc          #+#    #+#              #
#    Updated: 2017/01/19 16:11:22 by ccerbusc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Werror -Wextra -Iinclude -Ilibft
FILE = ft_ls.c merge_sort.c check_flags.c check_dirs.c aux.c r_m_flag.c \
	   l_flag.c l_flag_aux.c l_flag_aux2.c l_flag_aux3.c utils.c aux2.c
SRC = $(patsubst %.c, src/%.c, $(FILE))
OBJ = $(patsubst %.c, obj/%.o, $(FILE))

all: $(NAME)

$(OBJ): | obj

obj:
	@mkdir -p $@

obj/%.o: src/%.c
	@gcc $(FLAGS) -c $< -o $@

libft/libft.a:
	@make -C libft/

$(NAME): $(OBJ) libft/libft.a
	@gcc $(FLAGS) -Llibft -lft $(OBJ) -o $(NAME)

clean:
	@make -C libft fclean
	@/bin/rm -rf $(OBJ)
fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
