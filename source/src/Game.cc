//Game class implementation
//Main game loop
#include <SDL2/SDL.H>
#include "Game.h"
#include "Graphics.h"
#include "Input.h"
Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING); //Initializes stuff you want to set up in args
}

Game::~Game() {
	gameLoop(); //call gameloop here instead of main
}

namespace {
const int FPS;
const int MaxFrameTime = 5000/FPS;
}
void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event; //holds event that happens during frame
	//initializing game loop
	int lastFrameUpdate = SDL_GetTicks();
	while(true) {
		input.beginNewFrame();
		if(SDL_PollEvent(&event)) {
			if(event.type == SDL_KEYDOWN) {
				if(event.key.repeat == 0) {// zero if not being held
					input.keyDownEvent(event);
				}
			}
			else if(event.type == SDL_KEYUP) {
				input.keyUpEvent(event);	
			}
			else if(event.type == SDL_QUIT) {
				return;
			}
		}
		//escape has been pressed quit game
		if(input.hasKeyBeenPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}
	}
}

void Game::draw(Graphics &graphics) {

}

void Game::update(float elapseTime) {

}
