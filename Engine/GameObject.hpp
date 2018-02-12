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
	GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y);
	~GameObject();
	
	void update();
	void render();
	
	
	
	
private:
	
	int xPos;
	int yPos;
	
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
	
};

#endif /* GameObject_hpp */
