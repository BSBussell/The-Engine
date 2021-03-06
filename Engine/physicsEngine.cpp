//
//  physicsEngine.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/19/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "physicsEngine.hpp"

int physicsObject::counter;
//using namespace physicsEngine;

physicsEngine::physicsEngine(Camera* camera) {
	
	localCamera = camera;
}
physicsEngine::~physicsEngine() {
	
}

bool physicsEngine::checkAllCollision(SDL_Rect rect, int id) {
	for (auto &i : objects) {
		if (SDL_HasIntersection(&rect, &i->dest) && i->collidable && (i->id != id)) {
		
			return false;
		}
	}
	return true;
}

void physicsEngine::draw() {
	for (auto &i : objects) {
		if (i->collidable == 1){
			TextureManager::DrawRect(i->dest, localCamera,255,0,0);
		} else {
			TextureManager::DrawRect(i->dest, localCamera,255,255,255);
		}
	}
}

void physicsEngine::update(double deltaTime) {

	SDL_Rect newRectangle;
	for (int i = 0; i < std::max(objects.size(),inActiveObjects.size()); i++) {
		if (i < objects.size()) {
			newRectangle = localCamera->CalculateToCamera(objects[i]->dest);
			if (!Camera::cullCheck(newRectangle.x, newRectangle.y)) {
				physicsObject::counter--;
				inActiveObjects.push_back(objects[i]);
				objects.erase(objects.begin()+i);
				i--;
			} else {
				objects[i]->id = i;
				
			}
		}
		if (i < inActiveObjects.size()) {
			newRectangle = localCamera->CalculateToCamera(inActiveObjects[i]->dest);
			if (Camera::cullCheck(newRectangle.x, newRectangle.y)) {
				physicsObject::counter++;
				objects.push_back(inActiveObjects[i]);
				inActiveObjects.erase(inActiveObjects.begin()+i);
				
				objects[i]->id = i;
			
			}
		}
	}
}

void physicsEngine::addObject(physicsObject newObj) {
	
	objects.push_back(&newObj);
}


physicsObject::physicsObject(SDL_Rect rect, physicsEngine *world) {
	
	dest = rect;
	id = physicsObject::counter;
	physicsObject::counter++;
	localWorld = world;
	localWorld->addObject(*this);
	
}
physicsObject::~physicsObject() {
	
}
double physicsObject::moveX(double x, double deltaTime) {
	
	SDL_Rect testCase = dest;
	testCase.x += x*deltaTime;
	bool colCheck = localWorld -> checkAllCollision(testCase, id);
	
	if (colCheck) {
		dest.x += x*deltaTime;
	} else {
		//dest.x *= deltaTime;
	}
	std::cout << "DX: " << x*deltaTime << std::endl;
	
	updateProperties();
	return dest.x;
}
double physicsObject::moveY(double y, double deltaTime) {
	
	SDL_Rect testCase = dest;
	testCase.y += y*deltaTime;
	bool colCheck = localWorld -> checkAllCollision(testCase, id);
	
	if (colCheck) {
		dest.y += y*deltaTime;
	} else {
		//dest.y *= deltaTime;
	}
	//std::cout << "DY: " << y*deltaTime << std::endl;
	
	updateProperties();
	return dest.y;
}

void physicsObject::updateProperties() {
	
	localWorld->objects[id] = this;
}
