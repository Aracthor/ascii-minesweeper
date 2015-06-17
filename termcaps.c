#include <stdio.h>
#include <termios.h>

#include "termcaps.h"

int			cannon_mode(int flag)
{
  struct termios	config;

  if (tcgetattr(0, &config) != 0)
    {
      fprintf(stderr, "Configuration getting failed.\n");
      return (1);
    }
  config.c_lflag += flag ? ECHO : -ECHO;
  config.c_lflag += flag ? ICANON : -ICANON;
  config.c_cc[VMIN] = flag;
  config.c_cc[VTIME] = !flag;
  if (tcsetattr(0, TCSANOW, &config) != 0)
    {
      fprintf(stderr, "Configuration setting failed.\n");
      return (1);
    }
  return (0);
}

