#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "cursor.h"
#include "display.h"

static char	*
suppr_color(char *data, int *pc)
{
    data[(*pc)++] = '\033';
    data[(*pc)++] = '[';
    data[(*pc)++] = '0';
    data[(*pc)++] = 'm';

    return data;
}

static char	*
insert_bold(char *data, int *pc)
{
    data[(*pc)++] = '\033';
    data[(*pc)++] = '[';
    data[(*pc)++] = '1';
    data[(*pc)++] = 'm';

    return data;
}

static char	*
insert_background(char *data, int *pc, enum e_color color)
{
    data[(*pc)++] = '\033';
    data[(*pc)++] = '[';
    data[(*pc)++] = '4';
    data[(*pc)++] = '0' + color;
    data[(*pc)++] = 'm';

    return data;
}

static char	*
insert_color(char *data, int *pc, enum e_color color)
{
    data[(*pc)++] = '\033';
    data[(*pc)++] = '[';
    data[(*pc)++] = '3';
    data[(*pc)++] = '0' + color;
    data[(*pc)++] = 'm';

    return data;
}

static char	*
insert_char_color(char *data, int *pc, char c)
{
    enum e_color colors[9];
    int i;
    char *chars;

    chars = "12345678!";
    colors[0] = cyan;
    colors[1] = blue;
    colors[2] = green;
    colors[3] = yellow;
    colors[4] = magenta;
    colors[5] = red;
    colors[6] = white;
    colors[7] = red;
    colors[8] = red;

    for (i = 0; i < 9; ++i)
    if (chars[i] == c) {
        if (i == 1 || i >= 6)
            data = insert_bold(data, pc);
        data = insert_color(data, pc, colors[i]);
    }

    return data;
}

static char	*
border_line(struct s_grid *grid, char *data, int *pc)
{
    int i;

    data = suppr_color(data, pc);
    data[(*pc)++] = '#';
    for (i = 0; i < grid->longer * 2 - 1; ++i)
        data[(*pc)++] = '-';
    data[(*pc)++] = '#';
    data[(*pc)++] = '\n';

    return data;
}

static char	*
game_line(struct s_grid *grid, char *data, int *pc, int line, coord *select)
{
    int i;

    data[(*pc)++] = '|';
    for (i = 0; i < grid->longer; ++i) {
        if (grid->cases[line][i].display != '?' &&
            grid->cases[line][i].display != ' ')
                data = insert_char_color(data, pc, grid->cases[line][i].display);
        else if (grid->cases[line][i].display == '?')
            data = insert_bold(data, pc);

        data[(*pc)++] = grid->cases[line][i].display;

        if (line == select->y && i == select->x)
            data = insert_background(data, pc, black);

        data = suppr_color(data, pc);
        data[(*pc)++] = '|';
    }

    data[(*pc)++] = '\n';

    return data;
}

static char	*
center_line(struct s_grid *grid, char *data, int *pc)
{
    int i;

    data = suppr_color(data, pc);
    data[(*pc)++] = '|';

    for (i = 0; i < grid->longer - 1; ++i) {
        data[(*pc)++] = '-';
        data[(*pc)++] = '+';
    }

    data[(*pc)++] = '-';
    data[(*pc)++] = '|';
    data[(*pc)++] = '\n';

    return data;
}

char *
create_display(struct s_grid *grid)
{
    return (malloc((grid->longer + 2) * 2 * (grid->width + 2) * 2 * 5));
}

char *
write_game_data(struct s_grid *grid, char *display, int *pc)
{
    *pc += sprintf(display, "You found %d mines on %d.\n",
    grid->mines_selected, grid->mines);

    return display;
}

void
print_display(struct s_grid *grid, char *display, coord *select)
{
    coord	moove;
    int pc = 0;
    int i;

    init_cursor(select);

    system("clear");

    display = write_game_data(grid, display, &pc);
    display = border_line(grid, display, &pc);

    for (i = 0; i < grid->width; ++i) {
        display = game_line(grid, display, &pc, i, select);
        if (i + 1 < grid->width)
            display = center_line(grid, display, &pc);
    }

    display = border_line(grid, display, &pc);

    write(1, display, pc);

    moove = coordonne(0, grid->width);
    init_cursor(&moove);
    place_cursor(select);
}

