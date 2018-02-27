//
//  Map.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/11/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Map.hpp"
#include "TextureManager.hpp"


Map::Map(physicsEngine* world, Camera* camera, Window* window, json level) {

	int counter = 0;
	for ( auto &texture : level["Textures"]) {
		std::string filePath = texture;
		textures[counter] = TextureManager::LoadTexture(filePath.c_str());
		counter++;
	}

	localWorld = world;
	localCamera = camera;
	localWindow = window;

	src.x = dest.x =  0;
	src.y = dest.y =  0;
	src.w = dest.w = level["tileWidth"];
	src.h = dest.h = level["tileHeight"];
	
	crntMap = level;
	
	LoadMap(level);
}

Map::~Map() {
	
	
}

void Map::LoadMap(json Level) {
	
	int rowMax = Level["height"];
	int colMax = Level["width"];
	for (int row = 0; row < rowMax; row++) {
		for (int column = 0; column < colMax; column++) {
			if (Level["collisionLayer"][(column+(row*colMax))] == 1) {
				dest.x = column * int(Level["tileWidth"]);
				dest.y = row * int(Level["tileHeight"]);
				tile = new physicsObject(dest, localWorld);
				tile -> collidable = true;
				tile -> updateProperties();
			}
		}
	}
	delete tile;
}


void Map::DrawMap() {
	
	int type = 0;
	int xMax = crntMap["width"];
	int xMin = 0;
	int yMax = crntMap["height"];
	int yMin = 0;
	int windowW = localWindow -> getWidth();
	int windowH = localWindow -> getHeight();
	
	/*
		Calculates the lowest and highest values of the array 
		that will be visible on screen if drawn
		Also use absolute value math to ensure that the number
		is within the array
	 */
	int tileSize = crntMap["tileWidth"];
	
	if (localCamera -> viewCulling) {
		xMax = abs(localCamera -> CalculateCamX(windowW+(tileSize))/tileSize);
		xMax = xMax - (((xMax - 25)+abs(xMax - 25))/2);
		xMin = (localCamera -> CalculateCamX(-tileSize)/tileSize);
		xMin = (xMin + abs(xMin))/2;
		yMax = abs(localCamera -> CalculateCamY(windowH+tileSize)/tileSize);
		yMax = yMax - (((yMax - 20)+abs(yMax - 20))/2);
		yMin = (localCamera -> CalculateCamY(-tileSize)/tileSize);
		yMin = (yMin + abs(yMin))/2;
	}
	
	for (int row = yMin; row < yMax; row++) {
		for (int column = xMin; column < xMax; column++) {
			
			type = crntMap["baseLayer"][(column+(row*int(crntMap["width"])))];
			dest.x = (column * int(crntMap["tileWidth"]));
			dest.y = (row * int(crntMap["tileHeight"]));
			TextureManager::Draw(textures[type], src, dest,localCamera);
			
		}

	}

}
