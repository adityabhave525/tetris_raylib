#include <raylib.h>

int main()
{
    Color dark_blue = {44, 44, 127, 255};

    InitWindow(300, 600, "Tetris Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(dark_blue);

        EndDrawing();
    }

    CloseWindow();
}