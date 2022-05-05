/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:51:03 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/14 13:26:04 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	str_length2(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	unsigned int	src_length;
	unsigned int	dst_length;
	unsigned int	dst_temp;

	i = 0;
	src_length = str_length2(src);
	dst_length = str_length2(dest);
	if (size <= dst_length)
		return (size + src_length);
	dst_temp = dst_length;
	while (src[i] != '\0' && dst_temp + 1 < size)
	{
		dest[dst_temp] = src[i];
		dst_temp++;
		i++;
	}
	dest[dst_temp] = '\0';
	return (dst_length + src_length);
}
