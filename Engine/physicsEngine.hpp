//
//  physicsEngine.hpp
//  Engine
//
//  Created by Benjamin Bussell on 2/19/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#ifndef physicsEngine_hpp
#define physicsEngine_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <SDL2/SDL.h>
#include "Camera.hpp"
#include "TextureManager.hpp"


class physicsEngine;
class physicsObject;

class physicsObject {
	
public:
	physicsObject(SDL_Rect rect, physicsEngine &world);
	~physicsObject();
	
	
	double moveX(double x);
	double moveY(double y);
	
	bool collidable;
	
	SDL_Rect dest;
	

	
private :
	
	physicsEngine &localWorld;
	
	
};

class physicsEngine {
	
public:
	
	physicsEngine();
	~physicsEngine();
	
	void draw(Camera* camera);
	
	//static bool checkCollision(SDL_Rect rectA, SDL_Rect rectB);
	bool checkAllCollision(SDL_Rect rect);
	
	
	void addObject(physicsObject newObject);
	
	void update(Camera* camera);
	
protected:
	
	
	
private:
	std::vector<physicsObject> objects;
	std::vector<physicsObject> inActiveObjects;
	
	
};



#endif /* physicsEngine_hpp */
