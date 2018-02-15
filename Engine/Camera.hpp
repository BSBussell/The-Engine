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
//#include "GameObject.hpp"

class Camera {
public:
	Camera(double x, double y);
	~Camera();
	
	
	SDL_Rect CalculateToCamera( SDL_Rect dest);
	void AddToCamera(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
	
	void moveXBy(double x);
	void moveYBy(double y);
	void zoom(double zoom) {scale = zoom;};
	
	bool follow = true;
	//void follow(GameObject* object);
	
	double getX() {return xPos;};
	double getY() {return yPos;};
	
	
private:
	
	double xPos;
	double yPos;
	double scale = 1;
	
};

#endif /* Camera_hpp */
