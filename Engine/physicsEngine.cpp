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
		if (SDL_HasIntersection(&rect, &i.dest) && i.collidable && (i.id != id)) {
			//std::cout << "Collision" << std::endl;
			return false;
		}
	}
	return true;
}

void physicsEngine::draw() {
	for (auto &i : objects) {
		if (i.collidable == 1){
			TextureManager::DrawRect(i.dest, localCamera,255,0,0);
		} else {
			TextureManager::DrawRect(i.dest, localCamera,255,255,255);
		}
		//std::cout << i.collidable << std::endl;
	}
}

void physicsEngine::update() {
	
}

void physicsEngine::addObject(physicsObject newObj) {
	
	objects.push_back(newObj);
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
double physicsObject::moveX(double x) {
	
	SDL_Rect testCase = dest;
	testCase.x += x;
	bool colCheck = localWorld -> checkAllCollision(testCase, id);
	
	if (colCheck) {
		dest.x += x;
	}
	
	updateProperties();
	return dest.x;
}
double physicsObject::moveY(double y) {
	
	SDL_Rect testCase = dest;
	testCase.y += y;
	bool colCheck = localWorld -> checkAllCollision(testCase, id);
	
	if (colCheck) {
		dest.y += y;
	}
	
	updateProperties();
	return dest.y;
}

void physicsObject::updateProperties() {
	//id = 500;
	//std::cout << id << std::endl;
	localWorld->objects[id] = *this;
}
