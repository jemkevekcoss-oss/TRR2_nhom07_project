#include "constValue.h"
#include "raylib.h"

using namespace std;


/*
Game state


*/

int main() {
    // Khởi tạo cửa sổ 1 lần duy nhất
    InitWindow(screenWidth, screenHeight, "Graph Algorithm Visualizer");
    SetTargetFPS(60);

    //Visualizer app; // Khởi tạo toàn bộ game/app ở đây


    // Handle Input -> Update Program -> Render/Drawing 
    while (!WindowShouldClose()) {
        BeginDrawing();
        
        //app.Update(); // Xử lý input và logic thuật toán
        //app.Draw();   // Chỉ lo việc vẽ



        EndDrawing();
    }

    //app.Cleanup(); // Giải phóng bộ nhớ, âm thanh
    CloseWindow();
    return 0;
}