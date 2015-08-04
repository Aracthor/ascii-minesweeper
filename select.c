#include <stdio.h>
#include <unistd.h>

#include "cursor.h"
#include "display.h"
#include "grid.h"
#include "keyboard.h"
#include "select.h"

static bool
is_mine(struct s_grid *grid, coord *pos)
{
    bool is_a_mine;

    if (pos->x < 0 || pos->y < 0 ||
        pos->x >= grid->longer || pos->y >= grid->width ||
        grid->cases[pos->y][pos->x].mine == false)
        is_a_mine = false;
    else
        is_a_mine = true;

    return is_a_mine;
}

static int
count_mines(struct s_grid *grid, coord *pos)
{
    coord mooves[8];
    coord new_point;
    int i;
    int mines = 0;

    mooves[0] = coordonne(1, 0);
    mooves[1] = coordonne(1, 1);
    mooves[2] = coordonne(0, 1);
    mooves[3] = coordonne(-1, 1);
    mooves[4] = coordonne(-1, 0);
    mooves[5] = coordonne(-1, -1);
    mooves[6] = coordonne(0, -1);
    mooves[7] = coordonne(1, -1);
    for (i = 0; i < 8; ++i) {
        new_point = coord_sum(*pos, mooves[i]);
        mines += is_mine(grid, &new_point);
    }

    return mines;
}

static void
search_around(struct s_grid *grid, coord *point)
{
    coord mooves[8];
    coord new_point;
    int	i;

    mooves[0] = coordonne(1, 0);
    mooves[1] = coordonne(1, 1);
    mooves[2] = coordonne(0, 1);
    mooves[3] = coordonne(-1, 1);
    mooves[4] = coordonne(-1, 0);
    mooves[5] = coordonne(-1, -1);
    mooves[6] = coordonne(0, -1);
    mooves[7] = coordonne(1, -1);

    for (i = 0; i < 8; ++i) {
        new_point = coord_sum(*point, mooves[i]);
        if (new_point.x >= 0 && new_point.y >= 0 &&
            new_point.x < grid->longer && new_point.y < grid->width)
                select_nothing(grid, &new_point);
    }
}

static bool
search_victory(struct s_grid *grid, coord *point)
{
    coord pos;
    coord moovement = coordonne(0, grid->width);
    int left = LEFT;
    bool victory = true;

    for (pos.y = 0; pos.y < grid->width; ++pos.y)
        for (pos.x = 0; pos.x < grid->longer; ++pos.x)
            if (grid->cases[pos.y][pos.x].display == '?')
                victory = false;

    if (victory && grid->mines == grid->mines_selected) {
        init_cursor(point);
        place_cursor(&moovement);
        write(1, &left, sizeof(int));
        printf("Victory.\n");
        victory = true;
    } else
        victory = false;

    return (!victory);
}

bool
select_nothing(struct s_grid *grid, coord *point)
{
    coord moovement = coordonne(0, grid->width);
    int left = LEFT;
    int mines;
    bool game = true;

    if (grid->mines_created == false) {
        grid->mines_created = true;
        insert_mines(grid, point);
    }

    if (grid->cases[point->y][point->x].display != '!') {
        if (grid->cases[point->y][point->x].mine == true) {
            init_cursor(point);
            place_cursor(&moovement);
            write(1, &left, sizeof(int));
            printf("MIIIIIIIIIINE\n");
            game = false;
        } else {
            mines = count_mines(grid, point);
            if (mines > 0)
            grid->cases[point->y][point->x].display = '0' + mines;
            else if (grid->cases[point->y][point->x].display != ' ') {
                grid->cases[point->y][point->x].display = ' ';
                search_around(grid, point);
            }
        }
    }

    return game ? search_victory(grid, point) : false;
}

bool
select_mine(struct s_grid *grid, coord *point)
{
    if (grid->cases[point->y][point->x].display == '?') {
        grid->cases[point->y][point->x].display = '!';
        ++grid->mines_selected;
    } else if (grid->cases[point->y][point->x].display == '!') {
        grid->cases[point->y][point->x].display = '?';
        --grid->mines_selected;
    }

    return search_victory(grid, point);
}
