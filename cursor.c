#include <stdlib.h>
#include <unistd.h>

#include "cursor.h"
#include "keyboard.h"

void
init_cursor(coord *select)
{
    coord mooves;
    int	*moovement;
    int	i;

    mooves.x = select->x * 2 + 1;
    mooves.y = select->y * 2 + 1;
    moovement = malloc(sizeof(int) * (mooves.x + mooves.y + 2));

    for (i = 0; i < mooves.x; ++i)
        moovement[i] = LEFT;
    for (i = 0; i < mooves.y; ++i)
        moovement[mooves.x + i] = UP;

    moovement[mooves.x + i] = UP;
    moovement[mooves.x + i + 1] = DOWN;

    write(1, moovement, sizeof(int) * (mooves.x + mooves.y + 2));

    free(moovement);
}

void
place_cursor(coord *select)
{
    coord mooves;
    int	*moovement;
    int	i;

    mooves.x = select->x * 2 + 1;
    mooves.y = select->y * 2 + 1;
    moovement = malloc(sizeof(int) * (mooves.x + mooves.y));

    for (i = 0; i < mooves.x; ++i)
        moovement[i] = RIGHT;
    for (i = 0; i < mooves.y; ++i)
        moovement[mooves.x + i] = DOWN;

    write(1, moovement, sizeof(int) * (mooves.x + mooves.y));

    free(moovement);
}
