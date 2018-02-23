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
			//std::cout << "Collision" << std::endl;
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
		//std::cout << i.collidable << std::endl;
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
				//i--;
			} else {
				
				//int(objects.size());
				//objects.push_back(objects[i]);
				//objects.erase(objects.begin()+i);
			}
		}
	}
	// TODO: Write a loop that sorts through the object array
	//       And checks if it's positions can not be seen by the camera
	//		 If the camera doesn't see it then move it to the array inactive objs
	/*for (int i = 0; i< objects.size(); i++) {
		
		newRectangle = localCamera->CalculateToCamera(objects[i]->dest);
		if (!Camera::cullCheck(newRectangle.x, newRectangle.y)) {
			physicsObject::counter--;
			inActiveObjects.push_back(objects[i]);
			objects.erase(objects.begin()+i);
			i--;
		} else {
			objects[i]->id = i;//int(objects.size());
			//objects.push_back(objects[i]);
			//objects.erase(objects.begin()+i);
		}
	}
	
	for (int i = 0; i< inActiveObjects.size(); i++) {
		newRectangle = localCamera->CalculateToCamera(inActiveObjects[i]->dest);
		if (Camera::cullCheck(newRectangle.x, newRectangle.y)) {
			physicsObject::counter++;
			objects.push_back(inActiveObjects[i]);
			inActiveObjects.erase(inActiveObjects.begin()+i);
			
			objects[i]->id = i;
			//i--;
		} else {
			
			//int(objects.size());
			//objects.push_back(objects[i]);
			//objects.erase(objects.begin()+i);
		}
	}*/
	
	// TODO: Do the same thing with a loop for inActiveObjects
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
		std::cout <<x*deltaTime << std::endl;
	} else {
		//dest.x *= deltaTime;
	}
	
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
	
	
	updateProperties();
	return dest.y;
}

void physicsObject::updateProperties() {
	
	localWorld->objects[id] = this;
}
