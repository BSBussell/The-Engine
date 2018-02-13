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

class GameObject {
public:
	GameObject(const char* textureSheet, double x, double y);
	~GameObject();
	
	double xPos;
	double yPos;
	
	void update();
	void render();
	
	
	
private:
	
	
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	
	
};

#endif /* GameObject_hpp */
