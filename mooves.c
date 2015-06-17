#include <unistd.h>

#include "mooves.h"
#include "keyboard.h"

static void	moove_cursor(int moove)
{
  int		moovement[2];

  moovement[0] = moove;
  moovement[1] = moove;

  write(1, moovement, sizeof(moovement));
}

bool	moove_up(struct s_grid *grid, coord *select)
{
  (void)(grid);

  if (select->y > 0)
    --select->y;

  moove_cursor(UP);

  return (true);
}

bool	moove_down(struct s_grid *grid, coord *select)
{
  if (select->y < grid->width - 1)
    ++select->y;

  moove_cursor(DOWN);

  return (true);
}

bool	moove_right(struct s_grid *grid, coord *select)
{
  if (select->x < grid->longer - 1)
    ++select->x;

  moove_cursor(RIGHT);

  return (true);
}

bool	moove_left(struct s_grid *grid, coord *select)
{
  (void)(grid);

  if (select->x > 0)
    --select->x;

  moove_cursor(LEFT);

  return (true);
}

