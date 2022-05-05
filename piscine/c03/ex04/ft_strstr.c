/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:24:08 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/16 10:33:05 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <stdio.h>
char	*check_str(char *str, char *to_find, int index)
{
	int	i;
	int	j;

	j = index;
	i = 0;
	while (to_find[i] != '\0')
	{
		if (to_find[i] != str[j] || str[j] == '\0')
			return (0);
		j++;
		i++;
	}
	return (&str[index]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		trigger_on;
	char	trigger;
	char	*return_val;
	int		i;

	if (to_find[0] == '\0')
		return (str);
	trigger_on = 0;
	trigger = to_find[0];
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == trigger)
			trigger_on = 1;
		if (trigger_on == 1)
		{
			return_val = check_str(str, to_find, i);
			trigger_on = 0;
			if (return_val != 0)
				return (return_val);
		}
		i++;
	}
	return (0);
}
