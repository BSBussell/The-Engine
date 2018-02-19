//
//  Window.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/18/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Window.hpp"

Window::Window() {
	
	
}
Window::~Window() {
	
}

bool Window::init(const char *title, int xPos, int yPos, int width, int height, bool fullScreen) {
	
	int flags = 0 | SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_RESIZABLE;
	if (fullScreen) {
		flags = SDL_WINDOW_FULLSCREEN | SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_RESIZABLE;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL Initalized. . ." << std::endl;
		
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window) {
			std::cout << "Window Initalized. . ." << std::endl;
		}
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Initalized. . ." << std::endl;
		}
		
		return true;
		
		
		
	} else {
		return false;
	}
}

int Window::getWidth() {
	SDL_GetWindowSize(window, &width, &height);
	return width;
}
int Window::getHeight() {
	SDL_GetWindowSize(window, &width, &height);
	return height;
}

void Window::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}
