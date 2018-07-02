CC = gcc
SOURCES = *.c
EXECUTABLE = main

LDFLAGS :=
ifeq ($(OS),Windows_NT)
	LDFLAGS += -lglut -lGL -lm
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LDFLAGS += -lglut -lGL -lm
	endif
	ifeq ($(UNAME_S),Darwin)
		LDFLAGS += -framework GLUT -framework OpenGL
	endif
endif


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(SOURCES) 
	$(CC) $(SOURCES) -o $@ $(LDFLAGS)
