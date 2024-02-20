#include <iostream>
#include <cstring>
#include <cmath>

#define GRID_SIZE       32
#define GRID_LENGTH     (sizeof(grid) / sizeof(char))

#define OFFSET          16
#define PI              3.1415

char grid[GRID_SIZE][GRID_SIZE];

void drawCircleOutline(int radius)
{
    for (int i = 0; i < 360; i++)
    {
        float rad = (float) (i * PI / 180);             // Degree to Radian
        int x = round((sin(rad) * radius) + OFFSET);
        int y = round((cos(rad) * radius) + OFFSET);

        grid[y][x] = 'O';
    }
}

void drawCircleFill(int radius)
{
    for (int i = 0; i <= 180; i++)
    {
        float fR = (float) (i * PI / 180);              // Degree to Radian
        float eR = (float) ((360 - i) * PI / 180);      // Opposite value

        int fx = round((sin(fR) * radius) + OFFSET);
        int fy = round((cos(fR) * radius) + OFFSET);

        int ex = round((sin(eR) * radius) + OFFSET);

        grid[fy][fx] = 'O';

        for (int j = fx; j > ex; j--)
        {
            grid[fy][j] = 'O';
        }
    }
    
}

int main(int argc, char **argv)
{
    memset(grid, ' ', sizeof(grid));

    int radius = (argc == 2) ? atoi((char*)argv[1]) : 5;
    char type[8];

    memset(type, 0, sizeof(type));

    if (argc == 3)
        strcpy(type, argv[2]);
    else
        strcpy(type, "Outline");

    if (!strcmp(type, "Fill"))
        drawCircleFill(radius);
    else if (!strcmp(type, "Outline"))
        drawCircleOutline(radius);

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