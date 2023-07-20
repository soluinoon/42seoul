/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:54:48 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/14 14:25:48 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_length3(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				dest_length;

	dest_length = str_length3(dest);
	i = 0;
	while (i < nb)
	{
		if (src[i] != '\0')
		{
			dest[dest_length] = src[i];
			i++;
			dest_length++;
		}
	}
	dest[dest_length] = '\0';
	return (dest);
}
