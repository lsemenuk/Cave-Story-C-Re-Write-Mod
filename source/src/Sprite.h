#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
//Will hold all sprite info.
//All sprites will be derived from this

class Graphics;

class Sprite {
public:
	Sprite();
	Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY,
			int width, int height, float posX, float posY);
	virtual ~Sprite();
	virtual void update();//eventually going to need to override
	void draw(Graphics &graphics, int x, int y);
protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;
private:
	float _x;
	float _y;
};

#endif
