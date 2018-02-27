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

void Engine::init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen, json properties) {
	
	window = new Window();
	isRunning = window -> init(title, xPos, yPos, width, height, fullScreen);
	renderer = window -> getRenderer();
	
	if (properties["Camera"] != nullptr) {
		for (auto& CameraPlist : properties["Camera"]) {
			std::string tempName = CameraPlist["Name"];
			cameras[tempName] = new Camera(CameraPlist["x"],CameraPlist["y"],window);
			cameras[tempName] -> setCameraBounds(CameraPlist["boundX"], CameraPlist["boundY"], CameraPlist["width"], CameraPlist["height"]);
		}
	}
	
	if (properties["PhysicsWorld"] != nullptr) {
		for (auto& World : properties["PhysicsWorld"]) {
			std::string tempName = World["Name"];
			std::string temp = World["Camera"];
			physicsEngines[tempName] = new physicsEngine(cameras[temp]);
			
		}
	}
	std::cout << physicsEngines["world"] << std::endl;
	
	std::ifstream ifs("/Users/BenBusBoy/Documents/Engine/Engine/Engine/Data/Map.json");
	json Level = json::parse(ifs);
	
	if (Level != nullptr) {
		Level = Level["level1"];
		std::string tempCam = Level["Camera"];
		
		std::string temp = Level["World"];
		
		maps["level1"] = new Map(physicsEngines[temp],cameras[tempCam],window,Level);
	}
	if (properties["Player"] != nullptr) {
		json PlayerPlist = properties["Player"];
		std::string temp = PlayerPlist["Source"];
		const char* source = temp.c_str();
		std::string localEngine = PlayerPlist["World"];
		std::string localCamera = PlayerPlist["Camera"];
		std::string tempName = PlayerPlist["Name"];
		const char* name = tempName.c_str();
		players[name] = new Player(source, int(PlayerPlist["x"]), int(PlayerPlist["y"]), int(PlayerPlist["size"]), physicsEngines[localEngine], cameras[localCamera]);
		objects[name] = players[name] -> player;
	}
	if (properties["GameObject"] != nullptr) {
		for (auto &ObjectPlist: properties["GameObject"]) {
			std::string temp = ObjectPlist["Source"];
			const char* source = temp.c_str();
			std::string tempName = ObjectPlist["Name"];
			const char* name = tempName.c_str();
			std::string localEngine = ObjectPlist["World"];
			std::string localCamera = ObjectPlist["Camera"];
			objects[tempName] = new GameObject(source,name,ObjectPlist["x"],ObjectPlist["y"],ObjectPlist["width"],ObjectPlist["height"], physicsEngines[localEngine], cameras[localCamera]);
		}
	}
	
	if (properties["Camera"] != nullptr) {
		for (auto &Cameras : properties["Camera"]) {
			std::string tempName = Cameras["Following"];
			const char* newplrName = tempName.c_str();
			if (objects[newplrName] != nullptr) {
				std::string tempName = Cameras["Name"];
				const char* newName = tempName.c_str();
				cameras[newName] -> followObject(objects[newplrName]);
			}
		}
	}
	
	
}

void Engine::handleEvents() {
	
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			
			players["player"] -> events(event.key.keysym.sym);
			break;
		default:
			break;
	}
	
}

void Engine::update(double deltaTime) {
	
	for (auto &updWorlds : physicsEngines) {
		updWorlds.second -> update(deltaTime);
	}
	for (auto &characters : players) {
		characters.second -> update(deltaTime);
	}
	for (auto &GameObjects : objects) {
		GameObjects.second -> update(deltaTime);
	}
	for (auto &theCameras : cameras) {
		theCameras.second -> update(deltaTime);
	}
}

void Engine::render() {
	SDL_RenderClear(renderer);
	
	maps["level1"] -> DrawMap();
	for (auto &controllables: players) {
		controllables.second -> render();
	}
	
	for (auto &GameObjects : objects) {
		GameObjects.second -> render();
	}
	for (auto &worlds: physicsEngines) {
		worlds.second -> draw();
	}
	
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



