#include "Game.h"

using namespace std;


Game::Game() {
	currentState = MENU;
	running = true;


}


void Game::HandleInputEvents() {
	switch (currentState) {
		case GameState::MENU: {
			//handleMenuInput(); 

			break;
		}
		case GameState::EDITING: {
			//handleEditingInput(); 

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
			//updateEditing();

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

	DrawText("SIMULATOR",10,10,40,DARKBLUE);

	

	EndDrawing();

}
