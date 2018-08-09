CC=gcc -Wall -Wextra -Werror

ifeq ($(shell uname), Darwin)
	LFLAGS = -lmlx -framework OpenGL -framework AppKit
else
	LFLAGS = -lmlx -lXext -lX11 -lm
endif

NAME= wolf3d
SRC = $(wildcard *.c) $(wildcard libft/*.c)
OBJ = $(SRC:.c=.o)

%.o:		%.c
			@$(CC) $(FLAGS) -c $< -o $@ -I/opt/X11/include
			@echo "Compiling" $<

all	:$(NAME)

$(NAME)	:$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
	@echo "Creating wolf3d binary"

clean:
	rm *.o
	rm libft/*.o

fclean:	clean
	rm $(NAME)
