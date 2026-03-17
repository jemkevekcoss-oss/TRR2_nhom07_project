#pragma once
#include "constValue.h"
#include "Graph.h"

class Game {
public:
	GameState currentState;
	bool running;

	Graph graph;
	int nodeCount; // Tong so nut / vertex


	Game();
	~Game();

	void handleEvents();
	void Update();
	void Draw();

private:


};