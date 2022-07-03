#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char    *make_new_mem(char *mem);
char    *make_gnl(char *mem);
char    *make_line(char *mem, int fd);
size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *str, int c);
char    *ft_strjoin(char const *s1, char const *s2);

#endif
