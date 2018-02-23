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
#include <SDL2/SDL.h>

#include "Camera.hpp"
#include "TextureManager.hpp"


class physicsEngine;
class physicsObject;

class physicsObject {
	
public:
	
	
	
	physicsObject(SDL_Rect rect, physicsEngine *world);
	~physicsObject();
	
	int id;
	
	double moveX(double x);
	double moveY(double y);
	
	void updateProperties();
	
	bool collidable;
	
	SDL_Rect dest;
	
	static int counter;
	
private :
	
	physicsEngine *localWorld;
};

class physicsEngine {
	
public:
	
	physicsEngine(Camera* camera);
	~physicsEngine();
	
	
	void update();
	void draw();
	
	//static bool checkCollision(SDL_Rect rectA, SDL_Rect rectB);
	bool checkAllCollision(SDL_Rect rect, int id);
	
	
	void addObject(physicsObject newObject);
	
	std::vector<physicsObject*> objects;
	std::vector<physicsObject*> inActiveObjects;
	
protected:
	
	
	
private:
	
	Camera* localCamera;
	
	
	
};



#endif /* physicsEngine_hpp */
