#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int column);
    int grid[20][10];

private:
    int num_rows;
    int num_cols;
    int cell_size;
    std::vector<Color> colors;
};