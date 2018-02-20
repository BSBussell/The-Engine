//
//  physicsEngine.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/19/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "physicsEngine.hpp"

physicsEngine::physicsEngine() {
	
}
physicsEngine::~physicsEngine() {
	
}

void physicsEngine::addRectObject(SDL_Rect rect) {
	
	objects.push_back(rect);
}

void physicsEngine::update() {
	
}

bool physicsEngine::checkAllCollision(SDL_Rect rect) {
	for(int i=0; i < objects.size(); i++){
		
		if (checkCollision(rect, objects[i])) {
			return false;
		}
	}
	return true;
}

bool physicsEngine::checkCollision(SDL_Rect rectA, SDL_Rect rectB) {
	
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = rectA.x;
	rightA = rectA.x + rectA.w;
	topA = rectA.y;
	bottomA = rectA.y + rectA.h;
	
	leftB = rectB.x;
	rightB = rectB.x + rectB.w;
	topB = rectB.y;
	bottomB = rectB.y + rectB.h;
	
	if( bottomA <= topB ) {
		return false;
	}
	if( topA >= bottomB ) {
		return false;
	}
	if( rightA <= leftB ) {
		return false;
	}
	if( leftA >= rightB ) {
		return false;
	}
	
	return true;
}
