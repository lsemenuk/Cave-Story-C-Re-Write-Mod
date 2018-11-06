#include "Input.h"
//tracks keyboard events

//resets/tracks keys at the beginning of each new frame
//called every frame
void Input::beginNewFrame() {
	_pressedKeys.clear();
	_releasedKeys.clear();
}

void Input::keyDownEvent(const SDL_Event& event) {
	//indicating via bool key has been pressed in map
	_pressedKeys[event.key.keysym.scancode] = true;
	//if its pressed its being held
	_heldKeys[event.key.keysym.scancode] = true;
}

//calling this when a key is released
void Input::keyUpEvent(const SDL_Event& event) {
	//key has been released
	_releasedKeys[event.key.keysym.scancode] = true;
	//released = not being held anymore
	_heldKeys[event.key.keysym.scancode] = false;
}

bool Input::hasKeyBeenPressed(SDL_Scancode key) {
	//check if key has been pressed
	return _pressedKeys[key];
}

bool Input::hasKeyBeenReleased(SDL_Scancode key) {
	//check if key has been released
	return _releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
	//is key being held down
	return _heldKeys[key];
}
