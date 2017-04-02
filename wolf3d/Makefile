# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/09 17:25:46 by ccerbusc          #+#    #+#              #
#    Updated: 2016/03/15 18:58:45 by ccerbusc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
FLAGS = -Wall -Werror -Wextra -L./minilibx_macos -lmlx -framework OpenGL \
		-framework AppKit -I./ -L./libft -lft
FILE = wolf3d.c convert.c

all: $(NAME)

$(NAME):
	make -C libft re
	make -C minilibx_macos re
	gcc $(FLAGS) $(FILE) -o $(NAME)

fast:
	make -C libft re
	make -C minilibx_macos re
	gcc $(FLAGS) -Ofast $(FILE) -o $(NAME)

clean:
	make -C libft clean
	make -C minilibx_macos clean

fclean:
	make -C libft fclean
	/bin/rm -rf $(NAME)
	make -C minilibx_macos clean

re: fclean all
