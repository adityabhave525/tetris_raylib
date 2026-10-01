#include "block.h"

Block::Block()
{
    cell_size = 30;
    rotation_state = 0;
    colors = GetCellColors();
    row_offset = 0;
    column_offset = 0;
}

void Block::Draw()
{
    std::vector<Position> tiles = GetCellPositions();
    for (Position item : tiles)
    {
        DrawRectangle(item.column * cell_size + 1, item.row * cell_size + 1, cell_size - 1, cell_size - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
    row_offset += rows;
    column_offset += columns;
}

std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotation_state];
    std::vector<Position> moved_tiles;
    for (Position item : tiles)
    {
        Position new_pos = Position(item.row + row_offset, item.column + column_offset);
        moved_tiles.push_back(new_pos);
    }
    return moved_tiles;
}