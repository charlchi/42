# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 13:23:13 by cmoller           #+#    #+#              #
#    Updated: 2018/08/20 13:09:43 by cmoller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	printf
LIB = libftprintf.a
FLAGS =	-Wall -Wextra -Werror
CC = gcc
SRC = $(wildcard *.c) $(wildcard libft/*.c)
OBJ = $(SRC:.c=.o)

%.o:		%.c
			@echo "Compiling" $<
			@$(CC) $(FLAGS) -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJ)
			@echo "Creating binary" $(NAME)
			@$(CC) $(OBJ) -o $(NAME) $(LFLAGS)
		#	ar rc $(LIB) $(OBJ)
		#	ranlib $(LIB)

clean:
			/bin/rm -f $(NAME)
			/bin/rm -f $(LIB)

fclean: 	clean
			/bin/rm -f *.o
			/bin/rm -f libft/*.o

re: 		fclean all
