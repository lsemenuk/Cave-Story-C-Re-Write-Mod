//Implementing graphics class functionality
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Graphics.h"
#include "Globals.h"
Graphics::Graphics() {
	//set window size and pointers to window and renderer
	SDL_CreateWindowAndRenderer(globals::screenWidth, globals::screenHeight, 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, "Cave Story");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
	if(_spriteSheets.count(filePath) == 0) {//checks if already exists in map
		_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return _spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle){ 
	//coppies passed args to renderer
	SDL_RenderCopy(_renderer, texture, sourceRectangle, destinationRectangle); 
}

void Graphics::flip() {
	SDL_RenderPresent(_renderer);
}

void Graphics::clear() {
	SDL_RenderClear(_renderer);//clears renderer
}

SDL_Renderer* Graphics::getRenderer() const {
	return _renderer;//returns renderer
}
