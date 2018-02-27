//
//  Game.cpp
//  Scene
//
//  Created by Benjamin Bussell on 2/10/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

//#include <nlohmann/json.hpp>

#include "Scene.hpp"

#include "Window.hpp"
#include "Camera.hpp"
#include "TextureManager.hpp"


Window* window;
Camera* camera;


SDL_Renderer* Scene::renderer = nullptr;
//extern SDL_Window* window;


Scene::Scene() {
	
}

Scene::~Scene() {
	
}

void Scene::init(const char *title, int xPos, int yPos, int width, int height, bool fullScreen) {
	
	window = new Window();
	isRunning = window -> init(title, xPos, yPos, width, height, fullScreen);
	renderer = window -> getRenderer();
	
	camera = new Camera(0,0,window);
	
}

void Scene::handleEvents() {
	
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			
			break;
		default:
			break;
	}
	
}

void Scene::update(double deltaTime) {
	
	camera -> update(deltaTime);
}

void Scene::render() {
	SDL_RenderClear(renderer);
	
	
	SDL_RenderPresent(renderer);
}

void Scene::clean() {
	
	window -> clean();
	
	SDL_Quit();
	
	delete camera;
	delete window;
	
	std::cout << "Scene Cleaned. . ." << std::endl;
	
}



