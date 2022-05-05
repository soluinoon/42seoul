#include "get_next_line.h"
#define BUFFER_SIZE 100

char	*get_next_line(int fd)
{
	char			*str;
	char			buffer[BUFFER_SIZE];
	static	char	*mem;
	int				read_size;
	int				str_size;

	if (fd < 0 || fd > sysconf(OPEN_MAX) || fd == 1 || fd == 2)
		return (NULL);
	read_size = read(fd, buff, BUFFER_SIZE);
	if (!read_size)
		return (NULL);
	while (*buff != '\n' || *buff != EOF)
	{
		
	mem = buff;
	str = (char *)malloc(sizeof(char) * (read_size + 1));
	if (!str)
		return (NULL);
	while (

	return (str);
}	
