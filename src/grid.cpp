#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
    num_rows = 20;
    num_cols = 10;
    cell_size = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize()
{
    for (int row = 0; row < num_rows; row++)
    {
        for (int col = 0; col < num_cols; col++)
        {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print()
{
    for (int row = 0; row < num_rows; row++)
    {
        for (int col = 0; col < num_cols; col++)
        {
            std::cout << grid[row][col] << ' ';
        }
        std::cout << '\n';
    }
}

void Grid::Draw()
{
    for (int row = 0; row < num_rows; row++)
    {
        for (int col = 0; col < num_cols; col++)
        {
            int cell_value = grid[row][col];
            DrawRectangle(col * cell_size + 1, row * cell_size + 1, cell_size - 1, cell_size - 1, colors[cell_value]);
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < num_rows && column >= 0 && column < num_cols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for (int row = num_rows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row)
{
    for (int col = 0; col < num_cols; col++)
    {
        if (grid[row][col] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for (int col = 0; col < num_cols; col++)
    {
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int num_rows)
{
    for (int col = 0; col < num_cols; col++)
    {
        grid[row + num_rows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}
