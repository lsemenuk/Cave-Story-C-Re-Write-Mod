#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include <string>
#include <map>
#include <vector>
#include "Globals.h"
#include "Sprite.h"
//will hold info for the animated sprites
//will inherit from Sprite
class Graphics;

class AnimatedSprite : public Sprite{
public:
	AnimatedSprite();
   	AnimatedSprite(Graphics &graphics, const std::string& filePath, int sourceX,
			int sourceY, int width, int height, float posX, float posY, float timeToUpdate);
	//time to update is time between frames in animation
	
	//calling/playing animation by its name
	//default param for it the animation should loop or play once
	void playAnimation(std::string animation, bool once = false);
	
	//sets a timer so we know when to change animation frame
	void update(int elapsedTime);

	//draws sprite to screen
	void draw(Graphics& graphics, int x, int y);
	
	virtual void setUpAnimations();

private:
	//Basically a map full of a sprite animations
	//string is the name of the animation(set in set up animation)
	//SDL_Rect is the rectangle corresponsing to the sprite on sprite sheet
	std::map<std::string, std::vector<SDL_Rect> > _animations;

	std::map<std::string, Vector2> _offset;
	int _frameIndex;
	int _timeElapsed;
	bool _visible;
protected:
	double _timeToUpdate;//time between frames
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	//add animations to map
	void addAnimation(int frames, int x, int y,std::string& name, int width,
			int height, Vector2 offset);

	//clears all a sprites associated animations
	void resetAnimation();

	//stops current animation
	void stopAnimation();

	//changes animation visibility
	void setVisible(bool visible);

	//finish animation
	virtual void animationDone(std::string& currentAnimation);
};
#endif
