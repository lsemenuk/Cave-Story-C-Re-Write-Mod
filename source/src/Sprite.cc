#include "Sprite.h"
#include "Graphics.h"

 Sprite::Sprite() {};

Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY,
			int width, int height, float posX, float posY) : _x(posX), _y(posY) {

	//defining dimensions of what we are rendering
	_sourceRect.x = sourceX;
	_sourceRect.y = sourceY;
	_sourceRect.w = width;
	_sourceRect.h = height;

	//creates a texture from our existing surface(sprite image)
	//takes renderer and surface. Defined get renderer method for ease of use
	_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));

	if(_spriteSheet == NULL) {
		std::cout << "Unable to load the image" << std::endl;
	}

}

Sprite::~Sprite() {}

void Sprite::draw(Graphics &graphics, int x, int y) {
	SDL_Rect destinationRectangle = {x, y, _sourceRect.w, _sourceRect.h};
	
	//does drawing to screen
	graphics.blitSurface(_spriteSheet, &_sourceRect, &destinationRectangle);
}

void Sprite::update() {};

