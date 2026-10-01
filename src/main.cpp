#include <raylib.h>
#include "game.h"

double last_update_time = 0;

bool EventTriggered(double interval)
{
    double current_time = GetTime();
    if (current_time - last_update_time >= interval)
    {
        last_update_time = current_time;
        return true;
    }
    return false;
}

int main()
{
    Color dark_blue = {44, 44, 127, 255};

    InitWindow(300, 600, "Tetris Raylib");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose())
    {
        game.HandleInput();

        if (EventTriggered(0.02))
        {
            game.MoveBlockDown();
        }

        BeginDrawing();

        ClearBackground(dark_blue);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}