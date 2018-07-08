
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 13:23:13 by cmoller           #+#    #+#              #
#    Updated: 2018/07/02 12:45:54 by cmoller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap
FLAGS =		-Wall -Wextra -Werror
CC =		gcc
CH_OBJ =	checker.o parser.o pushswap.o stack.o util.o 
CH_FILES =	checker.c parser.c pushswap.c stack.c util.c 
PS_OBJ =	algo.o parser.o pushswap.o stack.o util.o 
PS_FILES =	algo.c parser.c pushswap.c stack.c util.c 

# compile libft in directory ../libft
# mv libft.a from that directory to algo_pushswap
# compile push swap executable with libft.a linked to it

all: 		checker push_swap

$(CH_OBJ):
			$(CC) $(FLAGS) -c $(CH_FILES)

$(PS_OBJ):
			$(CC) $(FLAGS) -c $(PS_FILES)

$(NAME):	$(OBJ)
			
checker:	$(CH_OBJ)
			$(CC) $(FLAGS) $(CH_OBJ) -o checker 

push_swap:		$(PS_OBJ)
			$(CC) $(FLAGS) $(PS_OBJ) -o push_swap 

clean:
			/bin/rm -f *.o

fclean: 	clean
			/bin/rm -f $(NAME)

re: 		fclean all

