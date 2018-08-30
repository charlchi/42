CC=gcc

ifeq ($(OS),Windows_NT)
	LFLAGS = -lglut -lGL -lm
else
	UNAME_S = $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LFLAGS = -lglut -lGL -lm
	endif
	ifeq ($(UNAME_S),Darwin)
		LFLAGS = -framework GLUT -framework OpenGL
	endif
endif

NAME= rtv1
SRC = $(wildcard *.c) $(wildcard libft/*.c)
OBJ = $(SRC:.c=.o)

%.o:		%.c
			@$(CC) $(FLAGS) -c $< -o $@
			@echo "Compiling" $<

all	:$(NAME)

$(NAME)	:$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
	@echo "Creating rtv1 binary"

clean:
	rm *.o
	rm libft/*.o

fclean:	clean
	rm $(NAME)
