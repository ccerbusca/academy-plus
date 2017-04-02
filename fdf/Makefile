# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/21 14:32:52 by ccerbusc          #+#    #+#              #
#    Updated: 2017/02/02 13:41:43 by ccerbusc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Werror -Wextra -lm -lmlx -framework OpenGL \
		-framework AppKit -I./includes -L./libft -lft
FILE = src/fdf.c src/convert.c src/drawing.c src/draw_line.c src/bonus.c \
	   src/bonus2.c

all: $(NAME)

$(NAME):
	make -C libft re
	gcc $(FLAGS) $(FILE) -o $(NAME)

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	/bin/rm -rf $(NAME)

re: fclean all
