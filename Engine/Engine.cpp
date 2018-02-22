//
//  Game.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/10/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Engine.hpp"
#include "Window.hpp"			// For handleing and creating a new Window
#include "Camera.hpp"			// For moaving a camera around and changing what can be seen on screen
#include "TextureManager.hpp"	// Handles Textures and stuff
#include "physicsEngine.hpp"	// Handles how objects will behave


#include "Map.hpp"				// For tile maps and drawing the map
#include "GameObject.hpp"		// Any thing to be drawn uses this
#include "Player.hpp"			// A Game object that can be move around



physicsEngine* world;
Camera* camera;
Window* window;

Player* player;
GameObject* object;
Map* map;

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
	camera -> setCameraBounds(0, 0, 2205, 1928);
	world = new physicsEngine(camera);
	
	map = new Map(world,camera,window);
	player = new Player("/Users/BenBusBoy/Documents/Engine/Engine/Assets.xcassets/purpleSquare.jpg", 255, 260, 20, world, camera);
	object = new GameObject("/Users/BenBusBoy/Documents/Engine/Engine/Assets.xcassets/Square.png","Colision Test",350,350,200,200, world);
	
	camera -> followObject(player -> player);
	
	
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
	
	world -> update();
	player -> update();
	object -> update();
	camera -> update();
}

void Engine::render() {
	SDL_RenderClear(renderer);
	
	map -> DrawMap();
	player -> render();
	object -> render(camera);
	
	SDL_RenderPresent(renderer);
}

void Engine::clean() {
	
	window -> clean();
	
	SDL_Quit();
	
	delete world;
	delete player;
	delete object;
	
	delete camera;
	delete window;
	delete map;
	
	std::cout << "Game Cleaned. . ." << std::endl;
	
}



