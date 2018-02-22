//
//  physicsEngine.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/19/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "physicsEngine.hpp"

//using namespace physicsEngine;

physicsEngine::physicsEngine() {
	
}
physicsEngine::~physicsEngine() {
	
}

bool physicsEngine::checkAllCollision(SDL_Rect rect) {
	for (auto &i : objects) {
		if (SDL_HasIntersection(&rect, &i.dest) && i.collidable) {
			std::cout << "Collision" << std::endl;
			return false;
		}
	}
	return true;
}

void physicsEngine::draw(Camera* camera) {
	for (auto &i : objects) {
		if (i.collidable){
				TextureManager::DrawRect(i.dest, camera,255,0,0);
		} else {
			TextureManager::DrawRect(i.dest, camera,255,255,255);
		}
	}
}

void physicsEngine::update(Camera* camera) {
	int a = 0;
	for (auto &i : objects) {
		SDL_Rect newRect;
		newRect = camera -> CalculateToCamera(i.dest);
		if (!Camera::cullCheck(newRect.x,newRect.y)) {
				inActiveObjects.push_back(i);
				objects.erase(objects.begin()+a);
				//std::cout << i.dest.x << std::endl;
		}
		a++;
		
	}
	a = 0;
	for (auto &i : inActiveObjects) {
		SDL_Rect newRect;
		newRect = camera -> CalculateToCamera(i.dest);
		if (Camera::cullCheck(newRect.x,newRect.y)) {
			objects.push_back(i);
			inActiveObjects.erase(objects.begin()+a);
		}
		a++;
	}
}

void physicsEngine::addObject(physicsObject newObj) {
	
	objects.push_back(newObj);
}


physicsObject::physicsObject(SDL_Rect rect, physicsEngine &world) : localWorld(world) {
	
	dest = rect;
	//localWorld = world;
	localWorld.addObject(*this);
	//world -> addObject(*this);
}
physicsObject::~physicsObject() {
	
}
double physicsObject::moveX(double x) {
	
	
	if (localWorld . checkAllCollision(dest)) {
		dest.x += x;
	} else {
		x*= -0.25;
		dest.x += x;
	}
	
	return dest.x;
}
double physicsObject::moveY(double y) {
	
	
	if (localWorld . checkAllCollision(dest)) {
		dest.y += y;
	} else {
		y*= -0.25;
		dest.y += y;
	}
	//dest.y += y;
	return dest.y;
}
