/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:04:44 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/19 17:26:24 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_power(int nb, int power)
{
	int	nb_temp;

	nb_temp = nb;
	if (power < 0)
		return (0);
	if (nb == 1 || power == 0)
		return (1);
	while (power > 1)
	{
		nb *= nb_temp;
		power--;
	}
	return (nb);
}
