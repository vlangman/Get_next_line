#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
#include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 10

int			get_next_line(const int fd, char **line);

#endif
