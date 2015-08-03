#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "coord.h"
#include "display.h"
#include "events.h"
#include "grid.h"
#include "termcaps.h"

static int
game_loop(struct s_grid *grid, char *display)
{
    coord select = coordonne(0, 0);
    coord last_select = coordonne(0, 0);
    bool game = true;

    while (game) {
        if (last_select.x == select.x && last_select.y == select.y)
            print_display(grid, display, &select);
        last_select = select;
        game = gere_events(grid, &select);
    }

    return 0;
}

int
main(int argc, char *argv[])
{
    struct s_grid grid;
    char *display;
    int return_value;

    srandom(time(NULL) * getpid());

    if (create_grid(argc, argv, &grid))
        return (1);

    cannon_mode(ENABLE);
    display = create_display(&grid);

    return_value = game_loop(&grid, display);

    cannon_mode(DISABLE);
    destroy_grid(&grid);
    free(display);

    return return_value;
}

