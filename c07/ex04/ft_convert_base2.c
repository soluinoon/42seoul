/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:41:56 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/23 14:37:17 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base_from);

int	str_check_length(char *arr);

int	check_malloc_length(int nbr, char *base_to)
{
	int	i;
	int	malloc_length;

	i = 0;
	malloc_length = 0;
	if (nbr == 0)
		return (1);
	while (base_to[i] != '\0')
		i++;
	while (nbr != 0)
	{
		nbr = nbr / i;
		malloc_length++;
	}
	return (malloc_length);
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

void	fill_change(int number, int malloc_length, char *change, char *base_to)
{
	int	i;
	int	base_length;
	int	temp;

	i = 0;
	base_length = str_length(base_to);
	while (i < malloc_length)
	{
		temp = number % base_length;
		change[malloc_length - 1 - i] = base_to[temp];
		number = number / base_length;
		i++;
	}
	change[malloc_length] = 0;
}

void	fill_change_minus(int number, int malloc_length, char *change,
char *base_to)
{
	int				i;
	int				base_length;
	int				temp;
	unsigned int	number_temp;

	i = 0;
	base_length = str_length(base_to);
	number_temp = -number;
	while (i < malloc_length)
	{
		temp = number_temp % base_length;
		change[malloc_length - i] = base_to[temp];
		number_temp = number_temp / base_length;
		i++;
	}
	change[malloc_length + 1] = '\0';
	change[0] = '-';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				from_to_int;
	char			*change;
	int				malloc_length;

	if (str_check_length(base_from) == -1 || str_check_length(base_to) == -1)
		return (0);
	from_to_int = ft_atoi_base(nbr, base_from);
	malloc_length = check_malloc_length(from_to_int, base_to);
	if (from_to_int < 0)
	{
		change = (char *)malloc(sizeof(char) * (malloc_length + 2));
		if (!change)
			return (0);
		fill_change_minus(from_to_int, malloc_length, change, base_to);
	}
	else
	{
		change = (char *)malloc(sizeof(char) * (malloc_length + 1));
		if (!change)
			return (0);
		fill_change(from_to_int, malloc_length, change, base_to);
	}
	return (change);
}
