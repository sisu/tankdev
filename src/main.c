#include <stdio.h>
#include "SDL.h"
#include "game.h"
#include "draw.h"

int main()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	SDL_SetVideoMode(800, 600, 0, SDL_OPENGL);

	initGL();

	loadMap("maps/test.map");

	int done=0;
	while(!done) {
		SDL_Event e;
		while(SDL_PollEvent(&e)) {
			if (e.type==SDL_QUIT)
				done=1;
		}

		updatePhysics();
		render();
		SDL_GL_SwapBuffers();
	}
	SDL_Quit();
	return 0;
}
