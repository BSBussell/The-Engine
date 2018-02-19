//
//  Window.hpp
//  Engine
//
//  Created by Benjamin Bussell on 2/18/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>

class Window {
public:
	
	Window();
	~Window();
	
	bool init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
	
	void resize(int width,int height);
	
	void clean();
	
	int getWidth();
	int getHeight();
	
	SDL_Renderer* getRenderer() {return renderer;};
	
private:
	
	SDL_Window* window;
	SDL_Renderer* renderer;
	
	int width;
	int height;
	
	bool fullscreen;
};


#endif /* Window_hpp */
