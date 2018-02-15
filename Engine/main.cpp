//
//  main.jpg
//  Engine
//
//  Created by Benjamin Bussell on 2/10/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Engine.hpp"

Engine *engine = nullptr;


int main( int argc, char* args[] ) {

	const int FPS = 120;
	const int frameDelay = 1000 / FPS;
	int fps =0;
	
	
	Uint32 frameStart;
	int frameTime;

	// Uses Class Created In  Engine.cpp to make the engine
	engine = new Engine();
	
	
	Uint32 startTime = SDL_GetTicks();
	int numFrames = 0;
	// Initalizes Window
	engine -> init("The Engine - ALPHA v0.0.0",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,640,false);

	while (engine -> running()) {
		
		frameStart = SDL_GetTicks();

		engine -> handleEvents();	// User Input, Keyboard etc
		engine -> update();			// Updates based on Events
		engine -> render();			// Draws based on Updates

		frameTime = SDL_GetTicks() - frameStart;
		numFrames ++;
		
		fps = (numFrames/(float)(SDL_GetTicks() - startTime) )*1000;
		//std::cout << ( numFrames/(float)(SDL_GetTicks() - startTime) )*1000 << std::endl;
		if (fps>FPS) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	engine -> clean();

	return 0;
}
