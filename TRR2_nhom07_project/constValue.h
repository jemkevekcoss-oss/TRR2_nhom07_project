#pragma once
#include <iostream> 
#include "raylib.h"
#include <vector>

enum GameState {
	MENU, //0
	EDITING, //1
	SIMULATING, //3
	PAUSE //4
};


inline  const int screenWidth = 1900;
inline const int screenHeight = 1000;
inline const float nodeRadius = 30;



