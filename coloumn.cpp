#include "coloumn.h"

bool convertColToInt(char col, int &x)
{
    switch (col)
    {
    case 'A':
    case 'a':
        x = 0;
        break;

    case 'B':
    case 'b':
        x = 1;
        break;

    case 'C':
    case 'c':
        x = 2;
        break;

    case 'D':
    case 'd':
        x = 3;
        break;

    case 'E':
    case 'e':
        x = 4;
        break;

    case 'F':
    case 'f':
        x = 5;
        break;

    case 'G':
    case 'g':
        x = 6;
        break;

    case 'H':
    case 'h':
        x = 7;
        break;

    default:
        return false;
        break;
    }
    return true;
}
