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

void Camera::update() {
	
	xVel = (xGoal - xPos)*friction;
	yVel = (yGoal - yPos)*friction;
	
	xPos += xVel;
	yPos += yVel;
	
	//xPos = ((xGoal - xPos));
	//yPos = ((yGoal - yPos));
	
	std::cout << "xPos" << xGoal-xPos << std::endl;
	std::cout << "yPos" << yGoal-yPos << std::endl;
}

void Camera::moveXBy(double x) {
	double lerp = 0.1;
	//xPos -= x*lerp;
	if (xVel < maxSpeed && xVel > -maxSpeed) {
		xVel += x*lerp;
	}
}

void Camera::moveYBy(double y) {
	double lerp = 0.1;
	//yPos -= y*lerp;
	if (yVel < maxSpeed && yVel > -maxSpeed) {
		yVel += y*lerp;
	}
}

void Camera::followObject(GameObject *object) {
	
	double objectX = object -> getX();
	double objectY = object -> getY();
	
	
	moveTo(objectX,objectY,1.0);
}

void Camera::moveTo(double X, double Y, double lerp = 1.0) {
	
	
	xGoal = ((-X)+375)*lerp;
	yGoal = ((-Y)+295)*lerp;
}

bool Camera::cullCheck(int X, int Y) {
	if (X < -128 || X > 800 || Y < -128 || Y > 640) {
		return false;
	} else {
		return true;
	}
}
