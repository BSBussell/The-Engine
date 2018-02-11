//
//  Game.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/10/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Game.hpp"

Engine::Engine() {
	
}

Engine::~Engine() {
	
}

void Engine::init(const char *title, int xPos, int yPos, int width, int height, bool fullScreen) {
	
	int flags = 0;
	if (fullScreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL Initalized. . ." << std::endl;
		
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window) {
			std::cout << "Window Initalized. . ." << std::endl;
		}
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Initalized. . ." << std::endl;
		}
		
		isRunning = true;
	} else {
		isRunning = false;
	}
}

void Engine::handleEvents() {
	
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {        // Stops Game Running when App is Quit
		case SDL_QUIT:
			isRunning = false;
			break;
		
		default:
			break;
	}
}

void Engine::update() {
	
}

void Engine::render() {
	SDL_RenderClear(renderer);
	// Draw Stuff Below. . .
	SDL_RenderPresent(renderer);
}

void Engine::clean() {
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	
	std::cout << "Game Cleaned. . ." << std::endl;
	
}






