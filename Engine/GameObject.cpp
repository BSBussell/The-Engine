//
//  GameObject.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/11/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "GameObject.hpp"
#include "TextureManager.hpp"

class Camera;

GameObject::GameObject(const char* textureSheet, const char* Name, double x, double y, double width = 200, double height = 200, physicsEngine* world = nullptr, Camera* camera = nullptr) {
	
	objTexture = TextureManager::LoadTexture(textureSheet);
	
	xPos = x;
	yPos = y;
	objWidth = width;
	objHeight = height;
	
	srcRect.h  = 200;
	srcRect.w  = 200;
	srcRect.x  =  0;
	srcRect.y  =  0;
	
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = srcRect.w / 4;
	destRect.h = srcRect.h / 4;
	
	object = new physicsObject(destRect,world);
	object -> collidable = true;
	object -> updateProperties();
	
	localCamera = camera;
	localWorld = world;
	
	ID = Name;
}

GameObject::~GameObject() {
	
	delete object;
}



void GameObject::update() {


	srcRect.h  = 200;
	srcRect.w  = 200;
	srcRect.x  =  0;
	srcRect.y  =  0;
	
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = srcRect.w / 4;
	destRect.h = srcRect.h / 4;
	
	//localWorld = world;
}

void GameObject::render() {

	TextureManager::Draw(objTexture, srcRect, destRect, localCamera);
}

void GameObject::moveXBy(double x) {
	//x = 1;
	xPos = object->moveX(x);
	
}
void GameObject::moveYBy(double y) {
	
	yPos = object->moveY(y);
}


