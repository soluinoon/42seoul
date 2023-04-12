/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:49:52 by jihonkim          #+#    #+#             */
/*   Updated: 2022/07/20 11:45:25 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*make_line(char *mem, int fd)
{
	int		read_count;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_count = 1;
	while (!ft_strchr(mem, '\n') && read_count != 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_count] = '\0';
		mem = ft_strjoin(mem, buffer);
	}
	free(buffer);
	return (mem);
}

char	*make_gnl(char *mem)
{
	char	*gnl;
	int		i;

	if (!mem[0])
		return (NULL);
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
		gnl[i] = '\0';
		gnl = ft_strjoin(gnl, "\n");
	}
	else
		gnl[i] = '\0';
	return (gnl);
}

char	*make_new_mem(char *mem)
{
	char	*new_mem;
	char	*temp;
	int		i;

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
	if (!new_mem)
		return (NULL);
	while (temp[i + 1] != '\0')
	{
		new_mem[i] = temp[i + 1];
		i++;
	}
	new_mem[i] = '\0';
	free(mem);
	return (new_mem);
}

char	*get_next_line(int fd)
{
	char			*gnl;
	static char		*mem;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	mem = make_line(mem, fd);
	if (!mem)
		return (NULL);
	gnl = make_gnl(mem);
	mem = make_new_mem(mem);
	return (gnl);
}
