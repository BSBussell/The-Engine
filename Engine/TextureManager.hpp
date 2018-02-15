//
//  TextureManager.hpp
//  Engine
//
//  Created by Benjamin Bussell on 2/11/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <stdio.h>
#include "Engine.hpp"
#include "Camera.hpp"

class TextureManager {
	
public:
	
	static SDL_Texture* LoadTexture(const char*fileName);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, Camera* camera);

};


#endif /* TextureManager_hpp */
