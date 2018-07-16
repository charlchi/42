INC=/usr/include
HT=x86_64
DOCP=do_cp



INCLIB=$(INC)/../lib

CC=gcc

CFLAGS= -I$(INC) -O3 -I../minilibx

NAME= fdf
SRC = fdf.c
OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L../minilibx -lmlx -L$(INCLIB) -lXext -lX11 -lm

clean	:
	rm -f $(NAME) $(OBJ) *~ core *.core


re	: clean all
