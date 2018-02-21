//
//  GameObject.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/11/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "GameObject.hpp"
#include "TextureManager.hpp"


GameObject::GameObject(const char* textureSheet, const char* Name, double x, double y, double width = 200, double height = 200, physicsEngine* world = nullptr) {
	
	objTexture = TextureManager::LoadTexture(textureSheet);
	
	xPos = x;
	yPos = y;
	objWidth = width;
	objHeight = height;
	
	object = new physicsObject(x,y,width,height);
	
	
	localWorld = world;
	
	ID = Name;
}

GameObject::~GameObject() {
	
}



void GameObject::update(physicsEngine* world) {


	srcRect.h  = 200;
	srcRect.w  = 200;
	srcRect.x  =  0;
	srcRect.y  =  0;
	
	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = srcRect.w / 4;
	destRect.h = srcRect.h / 4;
	
	localWorld = world;
}

void GameObject::render(Camera* camera) {

	TextureManager::Draw(objTexture, srcRect, destRect, camera);
}

void GameObject::moveXBy(double x) {
	
	xPos = object->moveX(x);
}
void GameObject::moveYBy(double y) {
	
	yPos = object->moveY(y);
}


