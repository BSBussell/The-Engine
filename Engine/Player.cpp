//
//  Player.cpp
//  Engine
//
//  Created by Benjamin Bussell on 2/12/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#include "Player.hpp"


Player::Player(const char* source, double x, double y, int speedLmt = 20, physicsEngine* world = nullptr, Camera* camera = nullptr) {
	
	player = new GameObject(source, "Player", x, y, 200,200, world, camera);
	//local_World = world;
	
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

void Player::update(double deltaTime) {
	
	dx *= friction;
	dy *= friction;
	
	//double x = player -> getX();
	//double y = player -> getY();
	
	//dx*= deltaTime;
	//dy*= deltaTime;
	
	if (dx< Speed && dx >-Speed) {
		player -> moveXBy(dx, deltaTime);
	}
	player -> moveYBy(dy, deltaTime);

	player -> update(deltaTime);
}

void Player::render() {
	
	player -> render();
}
