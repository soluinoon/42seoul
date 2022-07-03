#include "get_next_line.h"
#include <unistd.h>

char    *make_line(char *mem, int fd)
{
    int     read_count;
    char    *buffer;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
	read_count = 1;
    while (!ft_strchr(mem, '\n') && read_count != 0)
	{
		//printf("count\n");
		//printf("fd = %d\n", fd);
    	read_count = read(fd, buffer, BUFFER_SIZE);
		//printf("read count=%d\n", read_count);
    	if (read_count < 0)
    	{
        	return (NULL);
        	free(buffer);
    	}
		buffer[read_count] = '\0';
		//printf("buffer = %s\n", buffer);
		if (!mem)
			mem = (char *)malloc(sizeof(char) * 1);
		mem = ft_strjoin(mem, buffer);
		//printf("mem = %s\n", mem);
	}
    free(buffer);
	return (mem);
}


char	*make_gnl(char *mem)
{
    char    *gnl;
    int     i;

    //printf("input : %s\n", mem);
    if (!mem[0])
    {
        //printf("memerr\n");
        return (NULL);
    }
    i = 0;
    while (mem[i] != '\n' && mem[i] != '\0')
        i++;
    gnl = (char *)malloc(sizeof(char) * (i + 1));
    if (!gnl)
        return (NULL);
    i = 0;
    while (mem[i] != '\n' && mem[i] != '\0')
    {
        gnl[i] = mem[i];
        i++;
    }
    if (mem[i] == '\n')
    {
        //printf("nj\n");
        gnl[i] = '\n';
        ft_strjoin(gnl, "\0");
    }
    else
        gnl[i] = '\0';
    //printf("gnl = %s\n", gnl);
    return (gnl);
}

char    *make_new_mem(char *mem)
{
    char    *new_mem;
    char    *temp;
    int     i;

    i = 0;
    temp = ft_strchr(mem, '\n');
    if (!mem)
        return (NULL);
    if (!temp)
    {
        free(mem);
        return (NULL);
    }
    new_mem = (char *)malloc(sizeof(char) * ft_strlen(temp));
    while (temp[i + 1] != '\0')
    {
        new_mem[i] = temp[i + 1];
        i++;
    }
    new_mem[i] = '\0';
    free(mem);
    //printf("new_mem = %s\n", new_mem);
    return (new_mem);
}

char	*get_next_line(int fd)
{
	char			*gnl;
	static	char	*mem;
	int				read_size;
	int				str_size;
	
	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	// 이 부분 임시임
	mem = make_line(mem, fd);
	gnl = make_gnl(mem);
    mem = make_new_mem(mem);
	return (gnl);
}
