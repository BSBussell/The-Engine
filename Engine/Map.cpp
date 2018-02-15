//
//  Map.cpp
//  Engine
//  Ignorethis.git
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

Map::Map() {

	dirt = TextureManager::LoadTexture("/Users/BenBusBoy/Documents/Engine/Engine/Assets.xcassets/brownsquare.png");
	grass = TextureManager::LoadTexture("/Users/BenBusBoy/Documents/Engine/Engine/Assets.xcassets/greensquare.jpg");
	water = TextureManager::LoadTexture("/Users/BenBusBoy/Documents/Engine/Engine/Assets.xcassets/bluesquare.png");

	LoadMap(lvl1);

	src.x = dest.x =  0;
	src.y = dest.y =  0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
}

void Map::LoadMap(int arr[20][25]) {

	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap(Camera* camera) {
	
	int type = 0;

	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {
			
			type = map[row][column];
			dest.x = column * 32;
			dest.y = row * 32;

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
