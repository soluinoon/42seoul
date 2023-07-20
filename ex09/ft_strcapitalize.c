/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:02:57 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/13 16:23:55 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	check_and_change(char *str)
{
	if (*str > 96 && *str < 123)
	{
		*str = *str - 32;
	}
	return (*str);
}

char	check_big_alpha(char *str)
{
	if (*str > 64 && *str < 91)
	{
		*str = *str + 32;
	}
	return (*str);
}

int	check_special(char *str)
{
	if (!(((*str > 47) && (*str < 58)) || ((*str > 64) && (*str < 91)) || \
	((*str > 96) && (*str < 123))))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	str[0] = check_and_change(&str[0]);
	while (str[i] != 0)
	{
		if (flag == 0 && i != 0)
		{
			str[i] = check_big_alpha(&str[i]);
		}
		if (flag == 1)
		{
			str[i] = check_and_change(&str[i]);
			flag = 0;
		}
		flag = check_special(&str[i]);
		i++;
	}
	return (str);
}
