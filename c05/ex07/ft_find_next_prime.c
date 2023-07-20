/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:19:23 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/19 17:25:46 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_find_next_prime(int nb)
{
	int	i;
	int	max;

	i = 2;
	max = 2147483647;
	if (nb == 1 || nb == 0)
		return (2);
	while (nb < max)
	{
		while (i < nb)
		{
			if (nb % i == 0)
				break ;
			i++;
		}
		if (i == nb)
			return (nb);
		i = 2;
		nb++;
	}
	return (max);
}
