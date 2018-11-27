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
	//Need to set max fps for constant physics accross all hardware
	const int MAX_FPS = 50;
	const int MAX_FRAME_TIME = 5000 / MAX_FPS;
}
void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event; //holds event that happens during frame
	//assigning player sprite
	_player = AnimatedSprite(graphics, "/rsrc/MyChar.png",0, 0, 16, 16, 100, 100, 100);
	_player.setUpAnimations();
	_player.playAnimation("RunLeft");//created manually for testing
	//0,0 sets where the rectangle should begin for desired sprite 16,16 is 
	//where box ends because each sprite is 16x16
	int LAST_UPDATE_TIME = SDL_GetTicks(); //ms since SDL Lib was init
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
		const int CURRENT_TIME_MS = SDL_GetTicks();
		int PASSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		update(std::min(PASSED_TIME_MS, MAX_FRAME_TIME));//frame limiter
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		//need to display graphics to screen
		draw(graphics);
	}
}

void Game::draw(Graphics &graphics) {
	//1. clear what is in renderer
	graphics.clear();
	_player.draw(graphics,100,100);//same coordinates passed in on line 25
	graphics.flip();

}

void Game::update(float elapseTime) {
	_player.update(elapseTime);//calls animated sprite change animation
}
