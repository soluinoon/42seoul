/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:45:38 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/19 18:57:58 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int	check_cmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] != '\0' || str2[i] != '\0')
	{
		if (str[i] != str2[i])
			return (str[i] - str2[i]);
		i++;
	}
	return (0);
}

int	str_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	bubble(char **str, int size)
{
	int				i;
	int				j;
	char			*temp;

	i = 0;
	j = 2;
	while (i < size)
	{
		while (j < size + 1)
		{
			if (check_cmp(str[j - 1], str[j]) > 0)
			{
				temp = str[j];
				str[j] = str[j - 1];
				str[j - 1] = temp;
			}
			j++;
		}
		j = 2;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	leng;

	i = 1;
	j = 0;
	while (i < argc)
	{	
		leng = str_length(argv[i]);
		bubble(argv, argc - 1);
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
	return (0);
}
