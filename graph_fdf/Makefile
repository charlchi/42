CC=gcc

#ifeq ($(OS), Darwin)
	LFLAGS = -lmlx -framework OpenGL -framework AppKit
#else
#	LFLAGS = -lmlx -lXext -lX11 -lm
#endif

NAME= fdf
SRC = $(wildcard *.c) $(wildcard ../libft/*.c)
OBJ = $(SRC:.c=.o)

%.o:		%.c
			$(CC) $(FLAGS) -c $< -o $@

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
