//
//  TextureManager.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/11/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texture) {
	
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Engine::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	
	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Engine::renderer, tex, &src, &dest);
}
