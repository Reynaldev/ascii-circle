#include <iostream>
#include <cstring>
#include <cmath>

#define GRID_SIZE       32
#define GRID_LENGTH     (sizeof(grid) / sizeof(char))

#define OFFSET          16
#define PI              3.1415

char grid[GRID_SIZE][GRID_SIZE];

void printHelp()
{
    printf(
        "Usage:\n\t./a.exe [r] [arg]\n"
        "Example:\n\t./a.exe 10 o\n"
        "Arguments:\n"
        "\td\tDraw donut\n"
        "\tf\tDraw filled circle\n"
        "\to\tDraw outlined circle\n"
        "\n"
        "\thelp\tShow help\n"
    );
}

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
        float fr = (float) (i * PI / 180);              // Degree to Radian
        float er = (float) ((360 - i) * PI / 180);      // Opposite value

        int fx = round((sin(fr) * radius) + OFFSET);
        int fy = round((cos(fr) * radius) + OFFSET);

        int ex = round((sin(er) * radius) + OFFSET);

        grid[fy][fx] = 'O';

        for (int j = fx; j > ex; j--)
            grid[fy][j] = 'O';
    }
}

void drawDonut(int radius)
{
    int inRadius = 2;
    for (int i = 0; i < 180; i++)
    {
        float fr = (float)(i * PI / 180);

        // Outer line
        int ox = round((sin(fr) * radius) + OFFSET);
        int oy = round((cos(fr) * radius) + OFFSET);

        // Inner line
        int ix = round((sin(fr) * inRadius) + OFFSET);
        int iy = round((cos(fr) * inRadius) + OFFSET);

        float er = (float)((360 - i) * PI / 180);

        int eox = round((sin(er) * radius) + OFFSET);
        int eoy = round((cos(er) * radius) + OFFSET);

        int eix = round((sin(er) * inRadius) + OFFSET);
        int eiy = round((cos(er) * inRadius) + OFFSET);

        grid[oy][ox] = 'O';
        grid[iy][ix] = '|';
        // grid[eoy][eox] = 'O';
        // grid[eiy][eix] = 'O';

        for (int j = ox; j > eox; j--)
        {
            if ((j < ix) && (j > eix))
                grid[oy][j] = 'A';
            else
                grid[oy][j] = 'O';
        }
    }
}

int main(int argc, char **argv)
{
    memset(grid, ' ', sizeof(grid));

    if (!strcmp(*(argv + 1), "help"))
    {
        printHelp();
        return 0;
    }

    int radius = (argc >= 2) ? atoi(*(argv + 1)) : 5;
    char type;

    if (argc >= 3)
        type = **(argv + 2);
    else
        type = 'o';

    switch (type)
    {
        case 100:   // d
            drawDonut(radius);
            break;
        case 102:   // f
            drawCircleFill(radius);
            break;
        case 111:   // o
            drawCircleOutline(radius);
            break;
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