# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccerbusc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/18 17:07:43 by ccerbusc          #+#    #+#              #
#    Updated: 2015/11/19 15:16:06 by ccerbusc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS_LIB = -Wall -Werror -Wextra -c
FLAGS = -Wall -Werror -Wextra -L. -laux -o
NAME_LIBRARY = libaux.a
NAME = print
MAIN = print_stud.c
FILE = log_write.c get_utils.c ft_itoa.c print_util.c stock_data.c \
	   validate.c delete_data.c ft_strclr.c
FILE_OBJ = log_write.o get_utils.o ft_itoa.o print_util.o stock_data.o \
		   validate.o delete_data.o ft_strclr.o

all:
	@echo "Usage :"
	@echo "\tmake exe       - for generating the executable"
	@echo "\tmake clean     - for deleting all the object files"
	@echo "\tmake clean_lib - deleting all the object files and the library"
	@echo "\tmake fclean    - delete all the object files, the library and the executable"
	@echo ""

exe: $(NAME)

$(NAME_LIBRARY):
	gcc $(FLAGS_LIB) $(FILE)
	ar rc $(NAME_LIBRARY) $(FILE_OBJ)
	ranlib $(NAME_LIBRARY)

$(NAME): $(NAME_LIBRARY)
	gcc $(FLAGS) $(NAME) $(MAIN)


clean:
	/bin/rm -rf $(FILE_OBJ)

clean_lib: clean
	/bin/rm -rf $(NAME_LIBRARY)

fclean: clean_lib
	/bin/rm -rf $(NAME)

re: fclean print
