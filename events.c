#include <stdio.h>
#include <unistd.h>

#include "cursor.h"
#include "events.h"
#include "keyboard.h"
#include "mooves.h"
#include "select.h"

static bool
game_end(struct s_grid *grid, coord *select)
{
    coord moovement = coordonne(0, grid->width);
    int left = LEFT;

    init_cursor(select);
    place_cursor(&moovement);
    write(1, &left, sizeof(int));

    return false;
}

bool
gere_events(struct s_grid *grid, coord *select)
{
    int i;
    int key = 0;
    int keys[KEYS_NBR];
    bool (*functions[KEYS_NBR])(struct s_grid *grid, coord *select);
    bool game = true;

    keys[0] = ESCAPE;
    keys[1] = UP;
    keys[2] = DOWN;
    keys[3] = RIGHT;
    keys[4] = LEFT;
    keys[5] = 'z';
    keys[6] = 'x';

    functions[0] = &game_end;
    functions[1] = &moove_up;
    functions[2] = &moove_down;
    functions[3] = &moove_right;
    functions[4] = &moove_left;
    functions[5] = &select_nothing;
    functions[6] = &select_mine;

    if (read(0, &key, sizeof(int)) == -1) {
        fprintf(stderr, "Event readding problem. Sorry.\n");
        game = false;

    } else {
    for (i = 0; i < KEYS_NBR; ++i)
        if (key == keys[i])
            game = functions[i](grid, select);
    }

    return game;
}

