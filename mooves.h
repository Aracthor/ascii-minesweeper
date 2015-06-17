#ifndef MOOVES_H_
# define MOOVES_H_

# include "deminor.h"

bool	moove_up(struct s_grid *grid, coord *select);
bool	moove_down(struct s_grid *grid, coord *select);
bool	moove_right(struct s_grid *grid, coord *select);
bool	moove_left(struct s_grid *grid, coord *select);

#endif /* MOOVES_H_ */

