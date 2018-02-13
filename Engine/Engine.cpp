//
//  Game.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/10/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Engine.hpp"
#include "GameObject.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "Player.hpp"


//GameObject* player;
Player* player;
Map* map;

SDL_Renderer* Engine::renderer = nullptr;


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
	
	player = new Player("/Users/BenBusBoy/Documents/Engine/Engine/Assets.xcassets/Square.png", 250, 250, 20);
	map = new Map();

	
}

void Engine::handleEvents() {
	
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			player -> events(event.key.keysym.sym);
			break;
		default:
			break;
	}
	
}

void Engine::update() {
	
	player -> update();

	
	

}

void Engine::render() {
	SDL_RenderClear(renderer);
	
	map -> DrawMap();
	player -> render();
	
	SDL_RenderPresent(renderer);
}

void Engine::clean() {
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	
	std::cout << "Game Cleaned. . ." << std::endl;
	
}



