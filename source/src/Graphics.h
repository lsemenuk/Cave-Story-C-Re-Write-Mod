#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <map>
#include <string>

class SDL_Window;
class SDL_Renderer;

class Graphics {
public:
	//need to create a constructor 
	Graphics();
	//destructor
	~Graphics();

	//load an image into the sprite sheet map only once
	SDL_Surface* loadImage(const std::string &filePath);
	
	//Draws texture to specific area of screen
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
	
	//renders everthing to screen
	void flip();

	//clear the screen
	void clear();

	//returns render
	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* _window; //where the actual rendering/drawing is happening
	SDL_Renderer* _renderer; //doing the actual rendering into the window
	//sprite sheets and direct
	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif
