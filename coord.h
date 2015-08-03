#ifndef COORD_H_
#define COORD_H_

typedef struct s_coord {
    int x;
    int y;
} coord;

coord
coordonne(int x, int y);

coord
coord_sum(coord a, coord b);

coord
coord_mult(coord point, int nb);

int
coord_diff(coord a, coord b);

#endif /* COORD_H_ */

