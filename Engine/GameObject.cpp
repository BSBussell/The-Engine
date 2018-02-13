//
//  GameObject.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/11/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet, double x, double y) {
	
	objTexture = TextureManager::LoadTexture(textureSheet);
	
	xPos = x;
	yPos = y;
}

GameObject::~GameObject() {
	
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
}

void GameObject::render() {

	SDL_RenderCopy(Engine::renderer, objTexture, &srcRect, &destRect);
}

