#pragma once
#include "constValue.h"
#include "Graph.h"

class Game {
public:
	GameState currentState;
	bool running;

	

	Game();



	void HandleInputEvents();
	void Update();

	void Draw();

private:


};