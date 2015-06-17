#ifndef DEMINOR_H_
# define DEMINOR_H_

# include "booleen.h"
# include "color.h"
# include "coord.h"

typedef struct	s_case
{
  bool		mine;
  char		display;
}		t_case;

typedef struct	s_grid
{
  bool		mines_created;
  int		longer;
  int		width;
  int		mines;
  int		mines_selected;
  struct s_case	**cases;
}		t_grid;

typedef struct	s_display
{
  int		size;
  char		*data;
}		t_display;

#endif /* DEMINOR_H_ */

