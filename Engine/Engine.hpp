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
#include <fstream>

#include "json.hpp"

using json = nlohmann::json;

//#include "Camera.hpp"

class Camera;

class Engine {
	
public:
	Engine();
	~Engine();
	
	void init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen, json properties);
	void handleEvents();
	void update(double deltaTime);
	void render();
	void clean();
	
	bool running()  { return isRunning; }
	
	static SDL_Renderer *renderer;
	
private:
	
	bool isRunning;
	int crt = 0;
	//SDL_Window *window;
	
};

#endif /* Game_hpp */
