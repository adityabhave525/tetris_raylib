#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main()
{
    Color dark_blue = {44, 44, 127, 255};

    InitWindow(300, 600, "Tetris Raylib");
    SetTargetFPS(60);

    Grid grid = Grid();
    
    grid.Print();

    ZBlock block = ZBlock();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(dark_blue);

        grid.Draw();
        block.Draw();

        EndDrawing();
    }

    CloseWindow();
}