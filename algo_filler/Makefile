# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 13:23:13 by cmoller           #+#    #+#              #
#    Updated: 2018/06/28 09:15:04 by cmoller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME =	filler
FLAGS =	-Wall -Wextra -Werror
CC =	gcc
FILES = *.c gnl/*.c libft/*.c
INC = filler.h libft/libft.h gnl/get_next_line.h

all: 		$(NAME)

$(NAME):
			$(CC) $(FLAGS) $(FILES) -I $(INC)
			mv a.out $(NAME)

clean:
			/bin/rm -f $(NAME)

fclean: 	clean
			/bin/rm -f $(NAME)

re: 		fclean all
	
