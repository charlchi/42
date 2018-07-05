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

NAME =	push_swap
FLAGS =	-Wall -Wextra -Werror
CC =	gcc
OBJ =	ft_memalloc.o ft_putnbr_fd.o ft_strjoin.o ft_strrev.o \
FILES = ft_memalloc.c ft_putnbr_fd.c ft_strjoin.c ft_strrev.c \

# compile libft in directory ../libft
# mv libft.a from that directory to algo_pushswap
# compile push swap executable with libft.a linked to it

all: 		$(NAME)

$(OBJ):
			$(CC) $(FLAGS) -c $(FILES)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

clean:
			/bin/rm -f *.o

fclean: 	clean
			/bin/rm -f $(NAME)

re: 		fclean all

so: 		$(OBJ)
			gcc -g -fPIC -Wall -Werror -Wextra -pedantic *.c -shared -o libft.so
# keep this ^^ if you actually want to work from home
