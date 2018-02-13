//
//  Player.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/12/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Player.hpp"

Player::Player(const char* source, double x, double y, int speedLmt = 20) {
	
	player = new GameObject(source, x, y);
	maxSpeed = speedLmt;
	std::cout << "Player Initalized. . ." << std::endl;
}
Player::~Player() {

}

void Player::events(SDL_Keycode event) {
	
	if (event== SDLK_LEFT)
		if (dx > -maxSpeed)
			dx--;
	if (event == SDLK_RIGHT)
		if (dx < maxSpeed)
			dx++;
	
	if (event == SDLK_UP)
		if (dy > -maxSpeed)
			dy--;
	if (event == SDLK_DOWN)
		if (dx < maxSpeed)
			dy++;
}

void Player::update() {
	
	dx *= friction;
	dy *= friction;
	
	player -> xPos += dx;
	player -> yPos += dy;
	
	
	player -> update();
}

void Player::render() {
	player -> render();
}
