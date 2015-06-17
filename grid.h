#ifndef GRID_H_
# define GRID_H_

# include "deminor.h"

# define PARAMS_NBR	(3)

# define DEFAULT_LONGER	(20)
# define DEFAULT_WIDTH	(10)
# define DEFAULT_MINES	(30)

bool	create_grid(int argc, char **argv, struct s_grid *grid);
void	insert_mines(struct s_grid *grid, coord *select);
void	destroy_grid(struct s_grid *grid);

#endif /* GRID_H_ */

