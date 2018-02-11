//
//  main.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/10/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Game.hpp"

Engine *engine = nullptr;


int main( int argc, char* args[] ) {
	
	engine = new Engine();
	
	engine -> init("The Engine",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,false);
	
	while (engine -> running()) {
		engine -> handleEvents();
		engine -> update();
		engine -> render();
	}
	
	engine -> clean();
	
	return 0;
}
