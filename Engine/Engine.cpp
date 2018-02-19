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
#include "Camera.hpp"
#include "Player.hpp"
#include "Window.hpp"

Player* player;
Map* map;
Camera* camera;
Window* window;

SDL_Renderer* Engine::renderer = nullptr;
//extern SDL_Window* window;


Engine::Engine() {
	
}

Engine::~Engine() {
	
}

void Engine::init(const char *title, int xPos, int yPos, int width, int height, bool fullScreen) {
	
	
	window = new Window();
	isRunning = window -> init(title, xPos, yPos, width, height, fullScreen);
	renderer = window -> getRenderer();
	
	camera = new Camera(0,0,window);
	player = new Player("/Users/BenBusBoy/Documents/Engine/Engine/Assets.xcassets/purpleSquare.jpg", 250, 250, 20);
	
	map = new Map();
	
	//camera -> zoom(2);
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
	camera -> followObject(player -> player);
	camera -> update(window);
}

void Engine::render() {
	SDL_RenderClear(renderer);
	
	map -> DrawMap(camera, window);
	player -> render(camera);
	
	SDL_RenderPresent(renderer);
}

void Engine::clean() {
	
	window -> clean();
	SDL_Quit();
	
	std::cout << "Game Cleaned. . ." << std::endl;
	
}



