//
//  Componets.hpp
//  Engine
//
//  Created by Benjamin Bussell on 2/12/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#ifndef Componets_hpp
#define Componets_hpp

#include <stdio.h>
#include "ECS.hpp"

class PositionComponet : public Component {

private:
	int xpos = 0;
	int ypos = 0;

public:

	int x() { return xpos; }
	int y() { return ypos; }

	void init() override {
		xpos = 0;
		ypos = 0;
	}

	void update() override {
		xpos++;
		ypos++;
	}

	void setPos(int x, int y) {
		xpos = x;
		ypos = y;
	}

};


#endif /* Componets_hpp */
