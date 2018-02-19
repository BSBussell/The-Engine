//
//  Camera.hpp
//  Engine
//
//  Created by Benjamin Bussell on 2/14/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "GameObject.hpp"

//class GameObject;


class Camera {
public:
	Camera(double x, double y);
	~Camera();
	
	
	SDL_Rect CalculateToCamera( SDL_Rect dest);
	int CalculateCamX(int x) { return x - xPos; };
	int CalculateCamY(int y) {return y - yPos; };
	
	void AddToCamera(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
	
	void moveXBy(double x);
	void moveYBy(double y);
	
	void zoom(double zoom) {scale = zoom;};
	void followObject(GameObject* object);
	
	void update();
	
	double getX() {return xPos;};
	double getY() {return yPos;};
	double getCenterX() {return xPos+375;};
	double getCenterY() {return yPos+375;};
	
	bool viewCulling = true;
	bool cullCheck(int X, int Y);
	
private:
	
	bool follow = true;
	
	
	double xPos;
	double yPos;
	
	double xGoal;
	double yGoal;
	
	double xVel = 0.0;
	double yVel = 0.0;
	
	double maxSpeed = 25;
	double friction = 0.05;
	
	
	double scale = 1.0;
	
	void moveTo(double x, double y, double lerp);
};

#endif /* Camera_hpp */
