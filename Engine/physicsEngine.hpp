//
//  physicsEngine.hpp
//  Engine
//
//  Created by Benjamin Bussell on 2/19/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#ifndef ObjectHandler_hpp
#define ObjectHandler_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <SDL2/SDL.h>

class physicsEngine {
	
public:
	
	physicsEngine();
	~physicsEngine();
	
	//void addRectObject(SDL_Rect rect);
	
	static bool checkCollision(SDL_Rect rectA, SDL_Rect rectB);
	bool checkAllCollision(SDL_Rect rect);
	
	// Dude I don't even know what I'm doing anymore this might wind up a
	// colossal disaster
	class physicsObject {
		
		public:
			physicsObject();
			~physicsObject();
		
			double moveX(int x);
			double moveY(int y);
		private:
			double x;
			double y;
			double width;
			double height;
		
		
		
	};
	
	void update();
	
private:
	
	std::vector<SDL_Rect> objects;
};



#endif /* ObjectHandler_hpp */
