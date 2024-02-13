#include <iostream>
#include <cstring>
#include <cmath>

#define GRID_SIZE       32
#define GRID_LENGTH     (sizeof(grid) / sizeof(char))

#define OFFSET          16
#define PI              3.1415

char grid[GRID_SIZE][GRID_SIZE];

int main(int argc, char **argv)
{
    memset(grid, ' ', sizeof(grid));

    int radius = 5;
    
    if (argc == 2)
        radius = atoi((char*)argv[1]);

    // Make a circle
    for (int i = 0; i <= 360; i++)
    {
        float rad = (float) (i * PI / 180);             // Degree to Radian
        int x = round((sin(rad) * radius) + OFFSET);
        int y = round((cos(rad) * radius) + OFFSET);

        grid[y][x] = 'O';
        // printf("Rad: %.2f\t X: %f\t Y: %f\n", rad, x, y);
    }

    // Draw
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            printf("%c ", grid[i][j]);
        }

        putchar('\n');
    }

    return 0;
}