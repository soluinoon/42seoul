/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:27:38 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/21 19:00:12 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_square(int seg_counter)
{
	int	multi;

	multi = 1;
	while (seg_counter > 1)
	{
		multi = multi * 10;
		seg_counter--;
	}
	return (multi);
}

int	find_print_counter(char *str, int index)
{
	int				i;
	unsigned int	value;
	int				seg;

	seg = 1;
	value = 0;
	i = index;
	while (str[i] > 47 && str[i] < 58 && str[i] != '\0')
	{
		i++;
	}
	i--;
	while (i >= index)
	{
		value += (str[i] - '0') * ft_square(seg);
		seg++;
		i--;
	}
	return (value);
}

int	check_minus(char *str, int *index)
{
	int	i;
	int	minus;

	minus = 1;
	i = *index;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			minus *= -1;
		else if (str[i] > 47 && str[i] < 58)
			break ;
		else if (str[i] != '+')
			return (0);
		i++;
	}
	*index = i;
	return (minus);
}

int	ft_atoi(char *str)
{
	int	i;
	int	minus_counter;
	int	minus_flag;
	int	value;

	value = 0;
	minus_flag = 1;
	minus_counter = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '-' || str[i] == '+') && minus_flag == 1)
			minus_counter = check_minus(str, &i);
		if (minus_counter == 0)
			return (0);
		if (str[i] > 47 && str[i] < 58)
		{
			minus_flag = 0;
			value = find_print_counter(str, i);
			break ;
		}
		i++;
	}
	return (value * minus_counter);
}
