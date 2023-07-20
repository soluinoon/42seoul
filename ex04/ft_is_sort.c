/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihonkim <jihonkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:59:00 by jihonkim          #+#    #+#             */
/*   Updated: 2022/02/24 13:54:59 by jihonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	cresendo;
	int	decresendo;

	i = 1;
	cresendo = 1;
	decresendo = 1;
	while (i < length)
	{
		if (f(tab[i], tab[i - 1]) > 0)
			cresendo = 0;
		i++;
	}
	i = 1;
	while (i < length)
	{
		if (f(tab[i], tab[i - 1]) < 0)
			decresendo = 0;
		i++;
	}
	if (cresendo == 1 || decresendo == 1)
		return (1);
	return (0);
}
