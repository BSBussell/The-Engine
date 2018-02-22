//
//  Camera.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/14/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Camera.hpp"
#include "TextureManager.hpp"
#include "Window.hpp"

Window* Camera::window = nullptr;

Camera::Camera(double x, double y, Window* newwindow) {
	
	xPos = x;
	yPos = y;
	window = newwindow;
}
Camera::~Camera() {
	
}

SDL_Rect Camera::CalculateToCamera( SDL_Rect dest) {
	
	dest.x += int(xPos);
	dest.x *= scale;
	dest.y += int(yPos);
	dest.y *= scale;
	dest.h += 5+scale;
	dest.h *= scale;
	dest.w += 5+scale;
	dest.w *= scale;
	return dest;
}

void Camera::update(Window* wind) {
	
	xVel = (xGoal - xPos)*friction;
	yVel = (yGoal - yPos)*friction;
	
	if ( xPos + xVel > xBound || xPos + xVel < -wBound) {
		xVel = 0;
	}
	
	if ( yPos + yVel > yBound || yPos + yVel < -hBound) {
		yVel = 0;
	}
	xPos += xVel;
	yPos += yVel;
	
	//window = wind;
	windowWidth = window -> getWidth();
	windowHeight = window -> getHeight();
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
	
	xGoal = ((-X)+(windowWidth/2))*lerp;
	yGoal = ((-Y)+(windowHeight/2))*lerp;
}

bool Camera::cullCheck(int X, int Y) {
	
	int width = window -> getWidth();
	int height = window -> getHeight();
	
	if (X < -128 || X > (width*1.15) || Y < -128 || Y > (height*1.15)) {
		return false;
	} else {
		return true;
	}
}
