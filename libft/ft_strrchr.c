/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:11:59 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/29 21:28:39 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	length;

	length = 0;
	i = 0;
	while (str[length] != '\0')
		length++;
	while (length >= 0)
	{
		if (str[length] == (char)c)
		{
			while (length != 0)
			{
				str++;
				length--;
			}
			return ((char *)str);
		}
		length--;
	}
	return (0);
}
