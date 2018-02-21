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


void physicsEngine::update() {
	int a = 0;
	for (auto &i : objects) {
		if (!Camera::cullCheck(i.dest.x,i.dest.y)) {
			inActiveObjects.push_back(i);
			objects.erase(objects.begin()+a);
		}
		
	}
}


physicsObject::physicsObject(double x, double y, double w, double h) {
	
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
	
}
physicsObject::~physicsObject() {
	
}
double physicsObject::moveX(double x) {
	
	dest.x += x;
	
	return dest.x;
}
double physicsObject::moveY(double y) {
	
	dest.y += y;
	return dest.y;
}
