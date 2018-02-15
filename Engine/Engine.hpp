//
//  Game.hpp
//  Engine
//
//  Created by Benjamin Bussell on 2/10/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "Camera.hpp"


class Engine {
	
public:
	Engine();
	~Engine();
	
	void init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	
	Camera* camera;
	
	bool running()  { return isRunning; }
	
	static SDL_Renderer *renderer;
	
private:
	
	bool isRunning;
	int crt = 0;
	SDL_Window *window;
	
};

#endif /* Game_hpp */
