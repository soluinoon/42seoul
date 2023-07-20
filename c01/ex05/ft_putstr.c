/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:16:41 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/08 12:21:12 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
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
	write(1, str, length);
}
