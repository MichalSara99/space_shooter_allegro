#include "tools.hpp"

int random()
{
    return rand();
}

int randomInt(int min, int max)
{
    int res = rand() % (max - min + 1) + min;
    return res;
}

int euclidDistance(int x1, int y1, int x2, int y2)
{
    int difX = abs(x2 - x1);
    int difY = abs(y2 - y1);
    int sum = difX * difX + difY * difY;
    return (int)(sqrt(sum));
}

int sgn(int x)
{
    return (x < 0 ? -1 : 1);
}
