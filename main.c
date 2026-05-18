#include <stdio.h>
#include "raylib.h"
#include "extra.h"

typedef enum {
    STATE_MENU,
    STATE_PLAYING
} GameState;

int main()
{
    Color colorBackground = {187, 173, 160, 255};
    
    
    const int screenWidth = 102.5 * GRID_SIZE; //original = 410 (4x4)
    const int screenHeight = 113 * GRID_SIZE; //original = 450 (4x4)

    int grid[GRID_SIZE][GRID_SIZE];
    
    spawnRandomTile(grid);
    spawnRandomTile(grid);

    InitWindow(screenWidth,screenHeight,"2048 The Game");

    SetTargetFPS(60);
    int score = 0;
    int highScore = 0;

    GameState state = STATE_MENU;

    int btnW = 40 * GRID_SIZE, btnH = 12 * GRID_SIZE;
    int btnX = (screenWidth - btnW) / 2;
    int btnY = 65 * GRID_SIZE;

    int selectedBtn = 0;

    int btnStartY    = 65 * GRID_SIZE;

    while(!WindowShouldClose())
    {

        Vector2 mouse = GetMousePosition();

        // ── MENU ─────────────────────────────────────────────────────────
        if (state == STATE_MENU)
        {
            Rectangle startBtn = { btnX, btnStartY, btnW, btnH };
            bool hovered = CheckCollisionPointRec(mouse, startBtn);

            if ((hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) || IsKeyPressed(KEY_ENTER))
            {
                for (int i = 0; i < GRID_SIZE; i++)
                    for (int j = 0; j < GRID_SIZE; j++)
                        grid[i][j] = 0;
                score = 0;
                spawnRandomTile(grid);
                spawnRandomTile(grid);
                state = STATE_PLAYING;
            }

            BeginDrawing();
                ClearBackground(BEIGE);

                DrawText("2048",
                    (screenWidth - MeasureText("2048", 20 * GRID_SIZE)) / 2,
                    20 * GRID_SIZE, 20 * GRID_SIZE, DARKBROWN);

                const char *hs = highScore > 0 ? TextFormat("Best: %d", highScore) : "Best: ---";

                DrawText(hs,
                    (screenWidth - MeasureText(hs, 5 * GRID_SIZE)) / 2,
                    50 * GRID_SIZE, 5 * GRID_SIZE, DARKBROWN);

                DrawRectangle(btnX, btnY, btnW, btnH, YELLOW);

                const char *sl = "START";

                DrawText(sl,
                    btnX + (btnW - MeasureText(sl, 6 * GRID_SIZE)) / 2,
                    btnY + (btnH - 6 * GRID_SIZE) / 2,
                    6 * GRID_SIZE, ORANGE);

                const char *hint = "Press ENTER to start";
                DrawText(hint,
                    (screenWidth - MeasureText(hint, 5 * GRID_SIZE)) / 2,
                    83 * GRID_SIZE, 5 * GRID_SIZE, DARKBROWN);

            EndDrawing();
        }

        // ── PLAYING ──────────────────────────────────────────────────────
        else if(state == STATE_PLAYING)
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

             if (score > highScore) highScore = score;

            // Game over check
            int over = 1;
            for (int i = 0; i < GRID_SIZE && over; i++)
                for (int j = 0; j < GRID_SIZE && over; j++)
                {
                    if (grid[i][j] == 0) { over = 0; break; }
                    if (i+1 < GRID_SIZE && grid[i][j] == grid[i+1][j]) over = 0;
                    if (j+1 < GRID_SIZE && grid[i][j] == grid[i][j+1]) over = 0;
                }

            if(over) 
            {
                BeginDrawing();

                    ClearBackground(colorBackground);
                    
                    drawGrid(grid);
                
                    DrawText(TextFormat("Score: %08d", score), 30*GRID_SIZE, 102*GRID_SIZE, 5*GRID_SIZE, DARKBROWN); 
                  
                    DrawRectangle((screenWidth - 50*GRID_SIZE)/2,(screenWidth - 30*GRID_SIZE)/2,50*GRID_SIZE,30*GRID_SIZE,RED);
                    DrawText(TextFormat("GAME OVER"),30 * GRID_SIZE, 47 * GRID_SIZE, 7 * GRID_SIZE, DARKBROWN); 

                    DrawText(TextFormat("Best:  %08d", highScore),30 * GRID_SIZE, 107 * GRID_SIZE, 5 * GRID_SIZE, MAROON);

                EndDrawing();

                WaitTime(5);

                state = STATE_MENU;
                continue;
            }
            BeginDrawing();

                ClearBackground(colorBackground);
                
                drawGrid(grid);
            
                DrawText(TextFormat("Score: %08d", score), 30*GRID_SIZE, 102*GRID_SIZE, 5*GRID_SIZE, DARKBROWN); 
                //                           original values     120          415           20

                DrawText(TextFormat("Best:  %08d", highScore),30 * GRID_SIZE, 107 * GRID_SIZE, 5 * GRID_SIZE, MAROON);
            EndDrawing();
        }
        
        
    }

    CloseWindow();

    return 0;
}