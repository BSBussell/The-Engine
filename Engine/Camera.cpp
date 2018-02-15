//
//  Camera.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/14/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Camera.hpp"
#include "TextureManager.hpp"

Camera::Camera(double x, double y) {
	
	xPos = x;
	yPos = y;
}
Camera::~Camera() {
	
}

SDL_Rect Camera::CalculateToCamera( SDL_Rect dest) {
	
	dest.x += xPos;
	dest.y += yPos;
	dest.h = dest.h * scale;
	dest.w = dest.w * scale;
	return dest;
}

void Camera::moveXBy(double x) {
	xPos += x;
}

void Camera::moveYBy(double y) {
	yPos += y;
}
