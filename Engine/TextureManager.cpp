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

void TextureManager::DrawRect(SDL_Rect rect,Camera *camera,Uint8 r=255,Uint8 g=255,Uint8 b=255) {
	
	rect = camera -> CalculateToCamera(rect);
	SDL_SetRenderDrawColor(Engine::renderer, r, g, b, 255);
	SDL_RenderDrawRect(Engine::renderer, &rect);
	SDL_SetRenderDrawColor(Engine::renderer, 0, 0, 0, 255);
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, Camera* camera) {
	
	dest = camera -> CalculateToCamera(dest);
	if (camera -> cullCheck(dest.x, dest.y) || !camera -> viewCulling) {
		SDL_RenderCopy(Engine::renderer, tex, &src, &dest);
	}
}
