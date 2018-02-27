//
//  Map.hpp
//  Engine
//
//  Created by Benjamin Bussell on 2/11/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "json.hpp"

#include "Engine.hpp"
#include "Window.hpp"
#include "Camera.hpp"
#include "physicsEngine.hpp"

class Map {

public:
	
	/*!
	 * @discussion The Tile Map to be used with drawing and crap
	 */
	Map(physicsEngine* world, Camera* camera, Window* window, json level);
	~Map();
	
	void LoadMap(json Level);
	void DrawMap();
	
	
private:
	
	SDL_Rect src, dest;
	
	Window* localWindow;
	Camera* localCamera;
	physicsEngine* localWorld;
	physicsObject* tile;
	
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	
	std::map<int, SDL_Texture*> textures;

	json crntMap;
};

#endif /* Map_hpp */
