#include "Grid.h"

Grid::Grid(Vector2f position, Vector2f size)
{
	grid.setPosition(position);
	grid.setSize(size);
	grid.setFillColor(Color(99,161,222,50));
}

Grid::~Grid()
{
}

void Grid::Draw(RenderWindow & window)
{
	window.draw(grid);
}
