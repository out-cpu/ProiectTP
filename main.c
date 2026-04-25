#include <stdio.h>
#include "raylib.h"
#include "extra.h"



int main()
{
    Color colorBackground = {187, 173, 160, 255};
    
    
    const int screenWidth = 410;
    const int screenHeight = 450;

    int grid[GRID_SIZE][GRID_SIZE] = {{},{},{},{}};
    
    spawnRandomTile(grid);
    spawnRandomTile(grid);

    InitWindow(screenWidth,screenHeight,"2048 The Game");

    SetTargetFPS(60);
    int score=0;


    while(!WindowShouldClose())
    {
        int copy[GRID_SIZE][GRID_SIZE];
        for (int i = 0; i < GRID_SIZE; i++)
            for (int j = 0; j < GRID_SIZE; j++)
                copy[i][j] = grid[i][j];

        if (IsKeyPressed(KEY_LEFT))  moveLeft(grid);
        if (IsKeyPressed(KEY_RIGHT)) moveRight(grid);
        if (IsKeyPressed(KEY_UP)) moveUp(grid);
        if (IsKeyPressed(KEY_DOWN)) moveDown(grid);
        
        
        /////////////////////////////////////////////

        
        int changed=0;
        
        for (int i = 0; i < GRID_SIZE; i++)
            for (int j = 0; j < GRID_SIZE; j++)
                if(grid[i][j]!=copy[i][j])
                {
                    changed=1;
                }
        //////////////////////////
        
        if(changed)
        {
            for (int i = 0; i < GRID_SIZE; i++)
                for (int j = 0; j < GRID_SIZE; j++)
                {
                    score+=grid[i][j];
                }
            spawnRandomTile(grid);
        }
        
        BeginDrawing();

            ClearBackground(colorBackground);
            
            drawGrid(grid);
           
            DrawText(TextFormat("Score: %08d", score), 120, 415, 20, RED);
            

        EndDrawing();
    }

    CloseWindow();

    return 0;
}