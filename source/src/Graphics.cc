//Implementing graphics class functionality
#include <SDL2/SDL.h>
#include "Graphics.h"

Graphics::Graphics() {
	//set window size and pointers to window and renderer
	SDL_CreateWindowAndRenderer(640, 480, 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, "Cave Story");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(_window);
}
