//
//  Game.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/10/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Engine.hpp"
#include "TextureManager.hpp"


#include "Map.hpp"
#include "GameObject.hpp"
#include "Camera.hpp"
#include "Player.hpp"
#include "Window.hpp"
#include "physicsEngine.hpp"

Player* player;
GameObject* object;
Map* map;
physicsEngine* world;
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
	
	world = new physicsEngine();
	
	
	camera = new Camera(0,0,window);
	camera -> setCameraBounds(0, 0, 2205, 1928);
	
	map = new Map(world,camera,window);
	player = new Player("/Users/BenBusBoy/Documents/Engine/Engine/Assets.xcassets/purpleSquare.jpg", 255, 260, 20, world, camera);
	object = new GameObject("/Users/BenBusBoy/Documents/Engine/Engine/Assets.xcassets/Square.png","Colision Test",350,350,200,200, world);
	
	
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
	
	world -> update(camera);
	
	player -> update();
	object -> update();
	
	camera -> followObject(player -> player);
	camera -> update(window);
}

void Engine::render() {
	SDL_RenderClear(renderer);
	
	
	map -> DrawMap();
	player -> render();
	object -> render(camera);
	
	//world -> draw(camera);
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



