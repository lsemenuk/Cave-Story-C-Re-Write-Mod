#ifndef INPUT_H
#define INPUT_H
#include <SDL2/SDL.h>
#include <map> //from sdl lib


class Input {
public:
	void beginNewFrame();
	void keyUpEvent(const SDL_Event& event); //key up 
	void keyDownEvent(const SDL_Event& event); //key down

	bool hasKeyBeenPressed(SDL_Scancode key);
	bool hasKeyBeenReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);


private:
	std::map<SDL_Scancode, bool> _heldKeys; //instead of keycodes
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
};



#endif
