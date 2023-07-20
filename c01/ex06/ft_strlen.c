/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:31:34 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/08 12:22:28 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char	*str)
{
	int	counter;
	int	length;

	length = 0;
	counter = 0;
	while (str[counter] != 0)
	{
		length++;
		counter++;
	}
	return (length);
}
