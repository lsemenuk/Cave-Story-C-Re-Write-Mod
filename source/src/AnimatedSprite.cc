#include "AnimatedSprite.h"
#include "Graphics.h"
#include "Sprite.h"

AnimatedSprite::AnimatedSprite() {}
AnimatedSprite::AnimatedSprite(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY,
		int width, int height, float posX, float posY, float timeToUpdate) : Sprite(graphics, filePath,
			sourceX, sourceY, width, height, posX, posY), _frameIndex(0), _timeToUpdate(), _visible(true),
				_currentAnimationOnce(false), _currentAnimation("") {}

void AnimatedSprite::addAnimation(int frames, int x, int y, const std::string& name, int width,
			int height, Vector2 offset){

	std::vector<SDL_Rect> rectangles;
	for(size_t i = 0; i < frames; ++i) {
		SDL_Rect nextRect = {(i + x) * width, y, width, height};//this sets rect to grab next char on sprit sheet
		rectangles.push_back(nextRect);//all frames corresponding to ani are stored in rects
	}
	_animations.insert(std::pair<std::string, std::vector<SDL_Rect> >(name, rectangles));//adding ani's
	_offset.insert(std::pair<std::string, Vector2>(name, offset));
}

void AnimatedSprite::resetAnimation() {//just clears maps
	_animations.clear();
	_offset.clear();
}

void AnimatedSprite::playAnimation(std::string animation, bool once) {//used in update func
	_currentAnimationOnce = once;
	if(_currentAnimation != animation) {
		_currentAnimation = animation;
		_frameIndex = 0;
	}
}

void AnimatedSprite::setVisible(bool visible) {
	_visible = visible;
}

void AnimatedSprite::stopAnimation() {
	_frameIndex = 0;
	animationDone(_currentAnimation);
}

void AnimatedSprite::update(int elapsedTime) {
	Sprite::update();
	_timeElapsed += elapsedTime;
	if(_timeElapsed > _timeToUpdate) {
		_timeElapsed -= _timeToUpdate;
		if(_frameIndex < _animations[_currentAnimation].size() - 1) {
			_frameIndex += 1;
		}
		else {
			if(_currentAnimationOnce == true) {//make invisible afger first time
				setVisible(false);
			}
			_frameIndex = 0;//go back to beginning when end of animation
			animationDone(_currentAnimation);
		}
	}
}

void AnimatedSprite::draw(Graphics& graphics, int x, int y) {
	if(_visible) {
		SDL_Rect destRect;//where we drawing rect
		destRect.x = x + _offset[_currentAnimation].x;
		destRect.y = y + _offset[_currentAnimation].y;
		destRect.w = _sourceRect.w * globals::spriteScale;
		destRect.h = _sourceRect.h * globals::spriteScale;
		//get animation firsy by name to get vector then by vectors frame index
		SDL_Rect srcRect = _animations[_currentAnimation][_frameIndex];
		graphics.blitSurface(_spriteSheet, &srcRect, &destRect);
	}
}


void AnimatedSprite::animationDone(std::string& currentAnimation){

}

void AnimatedSprite::setUpAnimations() {
	//This is how we add an animation and name one
	addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0,0));
}

