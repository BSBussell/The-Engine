# The Engine
##### A Game Engine Built on C++ and Programmed by JSON
![ Build | Passing ](https://img.shields.io/badge/Build-runs-brightgreen.svg?longCache=true&style=flat-square)
![ Version | v0.0.5 ](https://img.shields.io/badge/Version-v0.0.5-blue.svg?longCache=true&style=flat-square)
[![GitHub license](https://img.shields.io/github/license/BSBussell/The-Engine.svg?style=flat-square)](https://github.com/BSBussell/The-Engine/blob/master/LICENSE)
[![GitHub issues](https://img.shields.io/github/issues/BSBussell/The-Engine.svg?style=flat-square)](https://github.com/BSBussell/The-Engine/issues)

------
![GIF Demonstration](https://github.com/BSBussell/The-Engine/raw/master/Media/Demonstration.gif)

```JSON
"Camera": {
		"cameras" : {
			"Name": "camera",
			"x" : 0,
			"y" : 0,
			"scale" : 1,
			"Following" : "player",
			"ExtScripts" : null
		}
	},
	"PhysicsWorld" : {
		"worlds" : {
			"Name" : "world",
			"Camera" : "camera",
			"DrawCollisions" : true
		}
	},
	"Player": {
		"Name" : "player",
		"x" : 255,
		"y" : 260,
		"Camera" : "camera",
		"World" : "world"
	},
```

### Features
* A Camera Library
    * With a follow function
* A Map loading library
    * Load's map from array
    * I Optimized this to the best of my ability.
* A GameObject Handler to make handling objects simple.
    * Handles sizing textures and stuff
* An optional Player Libray
    * Velocity based movement.
* Window/Renderer Manager

#### TODO:
- [x] Physics/Collision Engine
- [x] Load Game from JSON File
- [ ] GUI Editor
- [ ] Make Scriptable with Python/Lua

