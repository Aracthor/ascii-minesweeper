#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grid.h"

bool	get_arg(char *arg, struct s_grid *grid)
{
  int	*params_ref[PARAMS_NBR];
  int	i;
  int	param;
  char	*params[PARAMS_NBR];
  char	*ptr;
  bool	valid = false;

  params_ref[0] = &grid->longer;
  params_ref[1] = &grid->width;
  params_ref[2] = &grid->mines;
  params[0] = "width";
  params[1] = "height";
  params[2] = "mines";

  if ((ptr = strstr(arg, "=")) != NULL)
    {
      *ptr = '\0';
      for (i = 0; i < PARAMS_NBR; ++i)
	if (!strcmp(params[i], arg))
	  {
	    param = atoi(ptr + 1);
	    if (param > 0)
	      {
		valid = true;
		*params_ref[i] = atoi(ptr + 1);
	      }
	  }
    }

  if (!valid)
    fprintf(stderr, "Arg %s suck.\n", arg);

  free(arg);

  return (!valid);
}

bool	create_grid(int argc, char **argv, struct s_grid *grid)
{
  int	i;
  int	j;
  bool	valid = true;

  grid->mines_created = false;
  grid->longer = DEFAULT_LONGER;
  grid->width = DEFAULT_WIDTH;
  grid->mines = DEFAULT_MINES;
  grid->mines_selected = 0;

  for (i = 1; i < argc; ++i)
    if (get_arg(strdup(argv[i]), grid) != 0)
      valid = false;

  if (grid->longer * grid->width - 1 <= grid->mines)
    valid = false;

  if (valid)
    {
      grid->cases = malloc(sizeof(struct s_case *) * grid->width);
      for (i = 0; i < grid->width; ++i)
	{
	  grid->cases[i] = malloc(sizeof(struct s_case) * grid->longer);
	  for (j = 0; j < grid->longer; ++j)
	    {
	      grid->cases[i][j].mine = false;
	      grid->cases[i][j].display = '?';
	    }
	}
    }

  return (!valid);
}

void	insert_mines(struct s_grid *grid, coord *select)
{
  coord	point;
  int	i;

  for (i = 0; i < grid->mines; ++i)
    {
      do
        point = coordonne(random() % grid->longer, random() % grid->width);
      while (grid->cases[point.y][point.x].mine == true ||
	     (select->x == point.x && select->y == point.y));
      grid->cases[point.y][point.x].mine = true;
    }
}

void	destroy_grid(struct s_grid *grid)
{
  int	i;

  for (i = 0; i < grid->width; ++i)
    free(grid->cases[i]);
  free(grid->cases);
}

