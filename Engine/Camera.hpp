//
//  Camera.hpp
//  Engine
//
//  Created by Benjamin Bussell on 2/13/18.
//  Copyright © 2018 Benjamin Bussell. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>

class Camera {
public:
	Camera();
	~Camera();
	
	void init();
	void update();
	void render();
};

#endif /* Camera_hpp */
