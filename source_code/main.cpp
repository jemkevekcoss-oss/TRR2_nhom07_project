#include "constValue.h"
#include "Game.h"

using namespace std;


int main() {
    
    InitWindow(screenWidth, screenHeight, "Graph Algorithm Visualizer");
    SetTargetFPS(60);

    Game game;
    

    while (!WindowShouldClose() ) {
        
        
        // Handle Input -> Update Program -> Render/Drawing 
        
        game.HandleInputEvents();
        game.Update();
        game.Draw();
        
        

    }

    //game.Cleanup(); // Giải phóng bộ nhớ, âm thanh
    CloseWindow();
    return 0;
}