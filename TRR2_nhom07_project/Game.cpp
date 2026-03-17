#include "Game.h"

using namespace std;


Game::Game() {
	 currentState = EDITING; //Trang thai khai tao
	 running = true; //KHoi tao la game chay


}


void Game::handleEvents() {
    switch (currentState) {
    case GameState::MENU: {
        // Logic cho menu (nhấn nút Start thì chuyển sang EDITING)
        break;
    }
    case GameState::EDITING: {
        graph.handleEvents();

        break;
    }
    case GameState::SIMULATING: {

        break;
    }
    case GameState::PAUSE: {

        break;
    }
    }

}

void Game::Update() {
    switch (currentState) {
        case GameState::MENU: {
            // Logic cho menu (nhấn nút Start thì chuyển sang EDITING)
            break;
        }
        case GameState::EDITING: {
            graph.Update();

            break;
        }
        case GameState::SIMULATING: {

            break;
        }
        case GameState::PAUSE: {

            break;
        }
    }


}

void Game::Draw() {
    
    BeginDrawing();
    ClearBackground(WHITE);

    // Vẽ đồ thị
    graph.Draw();

    // Hiển thị trạng thái hiện tại ở góc màn hình
    if (currentState == GameState::EDITING) {
        DrawText("MODE: EDITING - Right click to select, 'C' to connect", 10, 10, 20, DARKBLUE);
    }

    EndDrawing();
    
}