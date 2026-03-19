#include "Game.h"

using namespace std;


Game::Game() {
	currentState = EDITING;  //Trang thai khoi tao
	running = true;


}


void Game::HandleInputEvents() {
	switch (currentState) {
		case GameState::MENU: {
			//handleMenuInput(); 

			break;
		}
		case GameState::EDITING: {
			graph.HandleInputEvents();

			break;
		}
		case GameState::SIMULATING: {
			//handleSimulatingInput(); 

			break;
		}
		case GameState::PAUSE: {
			//handlePauseInput(); 

			break;
		}
	}
}

void Game::Update() {
	switch (currentState) {
		case GameState::MENU: {
			//updateMenu(); 

			break;
		}
		case GameState::EDITING: {
			graph.Update();

			break;
		}
		case GameState::SIMULATING: {
			//updateSimulating();

			break;
		}
		case GameState::PAUSE: {
			//

			break;
		}
	}
}

void Game::Draw() {
	BeginDrawing();
	ClearBackground(WHITE);

	graph.Draw(); 

	DrawText("SIMULATOR",10,10,40,DARKBLUE);

	

	EndDrawing();

}
