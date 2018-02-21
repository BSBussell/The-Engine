//
//  GameObject.hpp
//  Engine
//
//  Created by Benjamin Bussell on 2/11/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>
//#include "physicsEngine.hpp"
//#include "Camera.hpp"
class Camera;

class GameObject {
public:
	/*!
	 * @discussion Creates a Graphic from the source using a texture source, and a X and Y position
	 * @param textureSheet  A String with the file path to your asset
	 * @param ID A String with the ID used to find your Object
	 * @param x  A Double specifing the X Position of the Object on the Screen
	 * @param y  A Double specifing the Y Position of the Object on the Screen
	 */
	GameObject(const char* textureSheet, const char* ID, double x, double y, double width, double height, physicsEngine* world);
	~GameObject();
	
	
	
	void update(physicsEngine* world);
	void render(Camera* camera);
	
	void moveXBy(double x);
	void moveYBy(double y);
	
	int getX() {return xPos;};
	int getY() {return yPos;};
	
	SDL_Rect srcRect, destRect;
	
private:
	
	const char* ID;
	
	double xPos;
	double yPos;
	double objWidth;
	double objHeight;
	
	physicsEngine* localWorld;
	physicsObject* object;
	
	SDL_Texture* objTexture;
	
	SDL_Rect scrnRect;
	
	
};

#endif /* GameObject_hpp */
