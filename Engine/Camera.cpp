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

Camera::Camera(double x, double y, Window* window) {
	
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

void Camera::update(Window* wind) {
	
	xVel = (xGoal - xPos)*friction;
	yVel = (yGoal - yPos)*friction;
	
	xPos += xVel;
	yPos += yVel;
	
	
	window = wind;
	windowWidth = wind -> getWidth();
	windowHeight = wind -> getHeight();
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
	
	if (X < -128 || X > (windowWidth*1.15) || Y < -128 || Y > (windowHeight*1.15)) {
		return false;
	} else {
		return true;
	}
}
