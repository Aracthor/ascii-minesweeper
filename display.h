#ifndef DISPLAY_H_
# define DISPLAY_H_

# include "deminor.h"

char	*create_display(struct s_grid *grid);
void	print_display(struct s_grid *grid, char *display, coord *selected);

#endif /* DISPLAY_H_ */

