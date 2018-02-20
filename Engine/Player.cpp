//
//  Player.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/12/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Player.hpp"


Player::Player(const char* source, double x, double y, int speedLmt = 20, physicsEngine* world = nullptr) {
	
	player = new GameObject(source, "Player", x, y, 200,200, world);
	Speed = speedLmt;
	std::cout << "Player Initalized. . ." << std::endl;
}
Player::~Player() {

}

void Player::events(SDL_Keycode event) {
	
	if (event== SDLK_LEFT)
		if (dx > -Speed)
			dx--;
	if (event == SDLK_RIGHT)
		if (dx < Speed)
			dx++;
	
	if (event == SDLK_UP)
		if (dy > -Speed)
			dy--;
	if (event == SDLK_DOWN)
		if (dx < Speed)
			dy++;
}

void Player::update(physicsEngine* world) {
	
	dx *= friction;
	dy *= friction;
	
	double x = player -> getX();
	double y = player -> getY();
	
	
	if (x+dx <=0 ) {
		dx =dx* -0.25;
	}
	if (y+dy <=0 ) {
		dy =dy* -0.25;
	}
	player -> moveXBy(dx);
	player -> moveYBy(dy);

	player -> update(world);
}

void Player::render(Camera* camera) {
	
	player -> render(camera);
}
