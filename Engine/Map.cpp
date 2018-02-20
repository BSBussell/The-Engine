//
//  Map.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/11/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Map.hpp"
#include "TextureManager.hpp"


int lvl1[20][25] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,1,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,2,1,1,1,1,1},
	{2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,1,2,2,2,2,2,1},
	{1,1,1,1,1,1,1,1,1,2,1,0,0,0,0,0,0,0,1,1,2,1,1,1,1},
	{1,0,0,0,0,0,0,0,1,2,1,0,0,0,0,0,0,0,0,1,2,1,0,0,1},
	{1,0,0,0,0,0,0,0,1,2,1,0,0,0,0,0,0,0,0,1,2,1,0,0,1},
	{1,0,0,0,0,1,1,1,1,2,1,1,1,1,0,0,0,0,0,1,2,1,0,0,1},
	{1,0,0,0,0,1,2,2,2,2,2,2,2,1,0,0,0,0,0,1,1,1,0,0,1},
	{1,0,0,0,0,1,2,1,1,1,1,1,2,1,1,1,1,1,1,0,0,0,0,0,1},
	{1,0,0,0,0,1,2,1,0,0,0,1,2,2,2,2,2,2,1,0,0,0,0,0,1},
	{1,0,0,0,0,1,2,1,1,1,1,1,2,1,1,1,1,2,1,0,0,0,0,0,1},
	{1,0,0,0,0,1,2,2,2,2,2,2,2,1,0,0,1,2,1,0,0,0,0,0,1},
	{1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,2,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,2,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

Map::Map(physicsEngine* world) {

	dirt = TextureManager::LoadTexture("/Users/BenBusBoy/Documents/Engine/Engine/Assets.xcassets/brownsquare.png");
	grass = TextureManager::LoadTexture("/Users/BenBusBoy/Documents/Engine/Engine/Assets.xcassets/greensquare.jpg");
	water = TextureManager::LoadTexture("/Users/BenBusBoy/Documents/Engine/Engine/Assets.xcassets/bluesquare.png");

	LoadMap(lvl1, world);

	src.x = dest.x =  0;
	src.y = dest.y =  0;
	src.w = dest.w = tileSize;
	src.h = dest.h = tileSize;
}

void Map::LoadMap(int arr[20][25], physicsEngine* world) {

	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {
			map[row][column] = arr[row][column];
			dest.x = column * tileSize;
			dest.y = row * tileSize;
			if (map[row][column] == 0) {
				world -> addRectObject(dest);
			}
		}
	}
}


void Map::DrawMap(Camera* camera, Window* window) {
	
	int type = 0;
	int xMax = 25;
	int xMin = 0;
	int yMax = 20;
	int yMin = 0;
	int windowW = window -> getWidth();
	int windowH = window -> getHeight();
	
	//tileSize = -129;
	
	/*
		Calculates the lowest and highest values of the array 
		that will be visible on screen if drawn
		Also use absolute value math to ensure that the number
		is within the array
	 */
	
	if (camera -> viewCulling) {
		xMax = abs(camera -> CalculateCamX(windowW+(tileSize))/tileSize);
		xMax = xMax - (((xMax - 25)+abs(xMax - 25))/2);
		xMin = (camera -> CalculateCamX(-tileSize)/tileSize);
		xMin = (xMin + abs(xMin))/2;
		yMax = abs(camera -> CalculateCamY(windowH+tileSize)/tileSize);
		yMax = yMax - (((yMax - 20)+abs(yMax - 20))/2);
		yMin = (camera -> CalculateCamY(-tileSize)/tileSize);
		yMin = (yMin + abs(yMin))/2;
	}
	//tileSize = 128;
	for (int row = yMin; row < yMax; row++) {
		for (int column = xMin; column < xMax; column++) {
			
			
			type = map[row][column];
			dest.x = (column * tileSize);
			dest.y = (row * tileSize);

			switch(type) {
				case 0:
					TextureManager::Draw(water, src, dest, camera);
					break;
				case 1:
					TextureManager::Draw(grass, src, dest,camera);
					break;
				case 2:
					TextureManager::Draw(dirt, src, dest,camera);
					break;
				default:
					break;
			}
		}

	}

}
