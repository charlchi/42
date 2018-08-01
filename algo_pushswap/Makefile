# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 13:23:13 by cmoller           #+#    #+#              #
#    Updated: 2018/07/31 13:27:05 by cmoller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS =	-Wall -Wextra -Werror
CC = gcc
PS_NAME =	push_swap
PS_SRC = $(filter-out checker.c, $(wildcard *.c)) $(wildcard libft/*.c)
PS_OBJ = $(PS_SRC:.c=.o)
CH_NAME =	checker
CH_SRC = $(filter-out algo.c, $(wildcard *.c)) $(wildcard libft/*.c)
CH_OBJ = $(CH_SRC:.c=.o)

%.o:		%.c
			$(CC) $(FLAGS) -c $< -o $@

all:		$(PS_NAME) $(CH_NAME)

$(CH_NAME):	$(CH_OBJ)
			$(CC) $(CH_OBJ) -o $(CH_NAME) $(LFLAGS)

$(PS_NAME):	$(PS_OBJ)
			$(CC) $(PS_OBJ) -o $(PS_NAME) $(LFLAGS)

clean:
			/bin/rm -f *.o
			/bin/rm -f libft/*.o

fclean: 	clean
			/bin/rm -f $(CH_NAME)
			/bin/rm -f $(PS_NAME)

re: 		fclean all
	
