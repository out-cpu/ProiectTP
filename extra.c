#include "extra.h"
#include "raylib.h"
#include <time.h>
#include <stdlib.h>

Color getTileColor(int value) {
    switch(value) {
        case 2:    return (Color){238, 228, 218, 255};
        case 4:    return (Color){237, 224, 200, 255};
        case 8:    return (Color){242, 177, 121, 255};
        case 16:   return (Color){245, 149, 99, 255};
        case 32:   return (Color){246, 124, 95, 255};
        case 64:   return (Color){246, 94, 59, 255};
        case 128:  return (Color){237, 207, 114, 255};
        case 256:  return (Color){237, 204, 97, 255};
        case 512:  return (Color){237, 200, 80, 255};
        case 1024: return (Color){237, 197, 63, 255};
        case 2048: return (Color){237, 194, 46, 255};
        default:   return (Color){205, 193, 180, 255}; 
    }
}

void processLine(int line[GRID_SIZE])
{
    int temp[GRID_SIZE] = {0};
    int index = 0;

    
    for (int i = 0; i < GRID_SIZE; i++) {
        if (line[i] != 0) {
            temp[index++] = line[i];
        }
    }

    
    for (int i = 0; i < index - 1; i++) {
        if (temp[i] == temp[i + 1]) {
            temp[i] *= 2;
            
            
            for (int j = i + 1; j < index - 1; j++) {
                temp[j] = temp[j + 1];
            }

            temp[index - 1] = 0;
            index--;
        }
    }

    
    for (int i = 0; i < GRID_SIZE; i++) {
        line[i] = (i < index) ? temp[i] : 0;
    }
}

void moveLeft(int grid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++) {
        processLine(grid[i]);
    }
}
/////DREAPTA

void reverse(int line[GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE / 2; i++) {
        int temp = line[i];
        line[i] = line[GRID_SIZE - 1 - i];
        line[GRID_SIZE - 1 - i] = temp;
    }
}

void moveRight(int grid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++) {
        reverse(grid[i]);
        processLine(grid[i]);
        reverse(grid[i]);
    }
}

///SUS 

void moveUp(int grid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            
        }
    }
}

///JOS

//void moveDown(int grid[GRID_SIZE][GRID_SIZE])




void drawGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    int tileSize = 90;
    int padding = 10;

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < 4; j++) {

            int x = j * (tileSize + padding) + padding;
            int y = i * (tileSize + padding) + padding;

            int value = grid[i][j];
            DrawRectangle(x, y, tileSize, tileSize, getTileColor(value));

            if (value != 0) {
                char text[10];
                sprintf(text, "%d", value);

                int fontSize = 30;
                int textWidth = MeasureText(text, fontSize);

                DrawText(text,
                         x + (tileSize - textWidth)/2,
                         y + (tileSize - fontSize)/2,
                         fontSize,
                         BLACK);
            }
        }
    }
}


void spawnRandomTile(int grid[GRID_SIZE][GRID_SIZE])
{   
    srand(time(NULL));

    int i1=rand()%GRID_SIZE;
    int j1=rand()%GRID_SIZE;

    int i2=rand()%GRID_SIZE;
    int j2=rand()%GRID_SIZE;

    int emptyTiles[GRID_SIZE*GRID_SIZE][2]={0};
    int count=0;
    
    for(int i=0;i<GRID_SIZE;i++)
    {
        for(int j=0;j<GRID_SIZE;j++)
        {
            if(grid[i][j]==0)
            {
                emptyTiles[count][0]=i;
                emptyTiles[count][1]=j;
                count++;
            }
        }
    }

    //daca e plina tabla
    if(count==0)return;
    
    //alege tile random
    int r=rand() % count;
    int i = emptyTiles[r][0];
    int j = emptyTiles[r][1];

    //90% sansa pt 2, 10% sansa pt 4
    grid[i][j] = (rand() % 10 == 0) ? 4 : 2;
    
}
