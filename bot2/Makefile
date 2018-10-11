# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smabuza <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/21 01:11:43 by smabuza           #+#    #+#              #
#    Updated: 2018/08/24 08:21:52 by smabuza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= smabuza.filler
FILES 	= main.c\
			readmaps.c\
			solution_algo.c
SRC 	= $(addprefix src/, $(FILES))
CC 		= gcc
CCDB 	= gcc -g
FLAGS 	= -Wall -Wextra -Werror
LINK	= -L library -lft
INCLUDE	= -I header/filler.h -I library/libft.h

all: $(NAME)

$(NAME):  lib
	$(CC) $(FLAGS) $(SRC) library/*.c $(INCLUDE) $(LINK) -o $(NAME)

clean:
	@rm -rf .obj/
	@make clean -C library

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C library

re: fclean all

db: 
	$(CCDB) $(FLAGS) $(SRC) library/*.c $(INCLUDE) $(LINK) -o $(NAME)

lib:
	@make -C library

relib:
	@make re -C library
