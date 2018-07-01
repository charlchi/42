# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 13:23:13 by cmoller           #+#    #+#              #
#    Updated: 2018/06/25 13:01:24 by cmoller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME =	lemin
FLAGS =	-Wall -Wextra -Werror
CC = gcc
INC = -Ilibft -Ignl
SRC = $(wildcard *.c) $(wildcard **/*.c)
OBJ = $(SRC:.c=.o)

%.o:		%.c
			$(CC) $(FLAGS) -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o lemin

clean:
			/bin/rm -f $(NAME)

fclean: 	clean
			/bin/rm -f $(NAME)
			/bin/rm -f build/*.o

re: 		fclean all
	
