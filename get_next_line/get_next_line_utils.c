#include "get_next_line.h"


size_t	ft_strlen(const char *str)
{
	// printf("len\n");
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}


char	*ft_strchr(const char *str, int c)
{
	int	i;

	// printf("chr\n");
	i = 0;
	if (!str)
	{
		return (0);
	}
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
		{
			//printf("str = %s\n", (char *)&str[i]);
			return ((char *)&str[i]);
		}		
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	str_count;
	char	*str;

	if (!s1 || !s2)
		return (0);
	i = 0;
	str_count = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	//printf("s1=%zu, s2=%zu\n", s1_len, s2_len);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	while (s1[i] != '\0')
		str[str_count++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[str_count++] = s2[i++];
	str[str_count] = '\0';
	return (str);
}
