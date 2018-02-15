//
//  Player.hpp
//  Engine
//
//  Created by Benjamin Bussell on 2/12/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "GameObject.hpp"
#include "Camera.hpp"

class Player {
	
public:
	
	Player(const char* textureSrc, double x, double y, int maxSpeed);
	~Player();
	
	GameObject* player;
	
	bool active;
	
	int Speed = 30;
	double friction = 0.988;
	
	void events(SDL_Keycode event);
	void update();
	void render(Camera* camera);
	
protected:
	
	char* movementType;
	char* customMovement();
	

private:
	
	double dx = 0;
	double dy = 0;
	
	
	
	
};


#endif /* Player_hpp */
