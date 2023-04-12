/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:24:19 by jihonkim          #+#    #+#             */
/*   Updated: 2022/04/29 21:28:22 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
		{
			while (i != 0)
			{
				str++;
				i--;
			}
			return ((char *)str);
		}
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)str + i);
	return (0);
}
