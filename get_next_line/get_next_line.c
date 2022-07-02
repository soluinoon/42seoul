//#include "get_next_line.h"
#define BUFFER_SIZE 100
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

// strjoin, strchr

char    *

char    *make_line(char *mem, int fd)
{
    int     read_count;
    char    *buffer;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    while (strchr(buffer, ' '))
    read_count = read(fd, buffer, BUFFER_SIZE);
    if (!read_count)
    {
        return (NULL);
        free(buffer);
    }
    buffer[read_count] = '\0';
    ft_strjoin(mem, buffer);
    
    free(buffer);
}

char	*get_next_line(int fd)
{
	char			*str;
	char			buffer[BUFFER_SIZE];
	static	char	*mem;
	int				read_size;
	int				str_size;

	if (fd < 0 || fd > sysconf(OPEN_MAX) || fd == 1 || fd == 2)
		return (NULL);
	

}	
