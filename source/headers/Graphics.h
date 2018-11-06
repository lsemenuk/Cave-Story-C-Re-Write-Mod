#ifndef GRAPHICS_H
#define GRAPHICS_H


class SDL_Window;
class SDL_Renderer;

class Graphics {
public:
	//need to create a constructor 
	Graphics();
	//destructor
	~Graphics();
private:
	SDL_Window* _window; //where the actual rendering/drawing is happening
	SDL_Renderer* _renderer; //doing the actual rendering into the window
};

#endif
