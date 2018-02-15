//
//  Camera.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/14/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Camera.hpp"
#include "TextureManager.hpp"

Camera::Camera(int x, int y) {
	
	xPos = x;
	yPos = y;
}
Camera::~Camera() {
	
}

SDL_Rect Camera::CalculateToCamera( SDL_Rect dest) {
	
	dest.x += xPos;
	dest.y += yPos;
	return dest;
}

void Camera::moveXBy(int x) {
	xPos += x;
}

void Camera::moveYBy(int y) {
	yPos += y;
}
