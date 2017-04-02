# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/09 17:25:46 by ccerbusc          #+#    #+#              #
#    Updated: 2017/01/12 20:06:21 by ccerbusc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL \
		-framework AppKit -I. -L./libft -lft
FILE = fractol.c draw_aux.c hook.c draw_mandelbrot.c draw_burning_ship.c \
	   draw_julia.c

all: $(NAME)

libft/libft.a:
	make -C libft re

$(NAME): libft/libft.a
	gcc $(FLAGS) $(FILE) -o $(NAME)

fast: libft/libft.a
	gcc $(FLAGS) -Ofast $(FILE) -o $(NAME)

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	/bin/rm -rf $(NAME)

re: fclean all
