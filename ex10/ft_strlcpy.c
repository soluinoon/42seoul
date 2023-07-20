/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:48:55 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/13 19:36:58 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	check_length(char *arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_length;
	unsigned int	dest_length;
	int				i;

	i = 0;
	if (size == 0)
		return (size);
	src_length = check_length(src);
	dest_length = check_length(dest);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_length);
}
