/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:54:48 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/16 19:39:33 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_length3(char *arr)
{
	unsigned int	i;

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
	unsigned int	dest_length;

	dest_length = str_length3(dest);
	i = 0;
	while (i < nb && src[i])
		dest[dest_length++] = src[i++];
	dest[dest_length] = '\0';
	return (dest);
}
