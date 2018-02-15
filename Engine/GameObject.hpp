//
//  GameObject.hpp
//  Engine
//
//  Created by Benjamin Bussell on 2/11/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "Camera.hpp"

class GameObject {
public:
	GameObject(const char* textureSheet, const char* ID, double x, double y);
	~GameObject();
	
	
	
	void update();
	void render(Camera* camera);
	
	void moveXBy(double x);
	void moveYBy(double y);
	
	int getX() {return xPos;};
	int getY() {return yPos;};
	
	
private:
	
	const char* ID;
	
	double xPos;
	double yPos;
	
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Rect scrnRect;
	
	
};

#endif /* GameObject_hpp */
