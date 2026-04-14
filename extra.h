#include "raylib.h"

#define GRID_SIZE 4


Color getTileColor(int value);
void drawGrid(int grid[GRID_SIZE][GRID_SIZE]);


void moveLeft(int grid[GRID_SIZE][GRID_SIZE]);
void moveRight(int grid[GRID_SIZE][GRID_SIZE]);
void moveUp(int grid[GRID_SIZE][GRID_SIZE]);
void moveDown(int grid[GRID_SIZE][GRID_SIZE]);

void spawnRandomTile(int grid[GRID_SIZE][GRID_SIZE]);