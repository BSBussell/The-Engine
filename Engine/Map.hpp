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
#include "Engine.hpp"
#include "Camera.hpp"

class Map {

public:
	
	/*!
	 * @discussion The Tile Map to be used
	 */
	Map();
	~Map();
	
	void LoadMap(int arr[20][25]);
	void DrawMap(Camera* camera);
	
	
private:
	
	SDL_Rect src, dest;
	
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];
	int tileSize = 128;
};

#endif /* Map_hpp */
