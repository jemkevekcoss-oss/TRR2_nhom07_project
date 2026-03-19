#pragma once
#include "constValue.h"
#include "Graph.h"

using namespace std;

class Game {
public:
	GameState currentState;
	bool running;

	Graph graph;

	Game();



	void HandleInputEvents();
	void Update();

	void Draw();

private:


};