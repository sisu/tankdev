OBJ=main.o draw.o game.o
CFLAGS=-Wall -O2 `sdl-config --cflags` -std=gnu99
LDFLAGS=`sdl-config --libs` -lGL -lGLU

all: tankdev

tankdev: $(OBJ)
	g++ $(OBJ) $(CFLAGS) $(LDFLAGS) -o $@

$(OBJ): %.o: %.c
	gcc $< -c -o $@ $(CFLAGS)
