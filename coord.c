#include <stdlib.h>

#include "coord.h"

coord
coordonne(int x, int y)
{
    coord	coords;

    coords.x = x;
    coords.y = y;
    return coords;
}

coord
coord_sum(coord a, coord b)
{
    return coordonne(a.x + b.x, a.y + b.y);
}

coord
coord_mult(coord point, int nb)
{
    return coordonne(point.x * nb, point.y * nb);
}

int
coord_diff(coord a, coord b)
{
    return (abs(a.x - b.x) + abs(a.y - b.y));
}
