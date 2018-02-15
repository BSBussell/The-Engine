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

class Camera {
public:
	Camera(int x, int y);
	~Camera();
	
	
	SDL_Rect CalculateToCamera( SDL_Rect dest);
	void AddToCamera(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
	
	void moveXBy(int x);
	void moveYBy(int y);
	
	int getX() {return xPos;};
	int getY() {return yPos;};
	
	
private:
	
	int xPos;
	int yPos;
};

#endif /* Camera_hpp */
