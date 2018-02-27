//
//  main.jpg
//  Engine
//
//  Created by Benjamin Bussell on 2/10/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include "json.hpp"

#include "Engine.hpp"


using json = nlohmann::json;

Engine *engine = nullptr;


int main( int argc, char* args[] ) {

	const int FPS = 30;
	const int frameDelay = 1000 / FPS;
	int fps = 0;
	
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;
	
	Uint32 frameStart;
	int frameTime;

	// Uses Class Created In  Engine.cpp to make the engine
	engine = new Engine();
	
	
	Uint32 startTime = SDL_GetTicks();
	int numFrames = 0;
	// Initalizes Window
	
	std::ifstream ifs("/Users/BenBusBoy/Documents/Engine/Engine/Engine/Data/Engine.json");
	json j = json::parse(ifs);
	
	json window = j["Window"];
	
	std::string title = window["title"].get<std::string>();
	
	engine -> init(title.c_str(),window["x"],window["y"],window["width"],window["height"],window["fullScreen"], j);

	while (engine -> running()) {
		
		frameStart = SDL_GetTicks();
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = ((NOW - LAST)*25 / (double)SDL_GetPerformanceFrequency() );
		
		engine -> handleEvents();	// User Input, Keyboard etc
		engine -> update(deltaTime);// Updates based on Events
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

	delete engine;
	
	return 0;
}
