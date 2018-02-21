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

class physicsObject {
	
public:
	physicsObject(double x, double y, double w, double h);
	~physicsObject();
	
	
	double moveX(double x);
	double moveY(double y);
	
	bool collidable = true;
	
	SDL_Rect dest;
	
protected:
	
	
	
	
	
};

class physicsEngine {
	
public:
	
	physicsEngine();
	~physicsEngine();
	
	
	
	//static bool checkCollision(SDL_Rect rectA, SDL_Rect rectB);
	//bool checkAllCollision(SDL_Rect rect);
	
	// Dude I don't even know what I'm doing anymore this might wind up a
	// colossal disaster
	
	
	//physicsObject addRectObject();
	
	void update();
	
private:
	
	std::vector<physicsObject> objects;
	std::vector<physicsObject> inActiveObjects;
	
};



#endif /* physicsEngine_hpp */
